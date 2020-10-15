#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <functional>

class Base;
using BasePtr = std::unique_ptr<Base>;
using ConstructFunc = std::function<BasePtr()>;

std::map<std::string, ConstructFunc>& get_objects();

template<typename T>
void add_object()
{
    get_objects()[typeid(T).name()] = std::make_unique<T>;
}

template<typename T>
class StaticClassConstructor {
public:
    StaticClassConstructor() {
        add_object<T>();
    }
};

class Base {
public:
    static bool make_obj(std::string type, BasePtr& ptr);
    virtual const std::string& get_name()=0;

};

template<typename T>
class TemplateBase : public Base {
public:
    virtual const std::string& get_name() override = 0;
private:
    static StaticClassConstructor<T> m;
};
