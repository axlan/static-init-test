// base.cpp

#include "base.h"


std::map<std::string, ConstructFunc>& get_objects()
{
    static std::map<std::string, ConstructFunc> construct_map;
    return construct_map;
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

template<typename T>
StaticClassConstructor<T> TemplateBase<T>::m = StaticClassConstructor<>();
