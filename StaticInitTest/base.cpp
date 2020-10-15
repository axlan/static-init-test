// base.cpp

#include "base.h"


std::map<std::string, ConstructFunc>& get_objects()
{
    static std::map<std::string, ConstructFunc> construct_map;
    return construct_map;
}

void add_object(std::string name, const ConstructFunc& constructor)
{
    get_objects()[name] = constructor;
}

bool Base::make_obj(std::string type, BasePtr& ptr)
{
    auto search = get_objects().find(type);
    if (search == get_objects().end()) {
        return false;
    } else {
        ptr = (search->second)();
        return true;
    }
}


StaticClassConstructor::StaticClassConstructor(std::string name, const ConstructFunc& constructor) {
    // Notify when the static member is created
    add_object(name, constructor);
}
