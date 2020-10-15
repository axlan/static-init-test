#pragma once
#include <map>
#include <iostream>
#include <memory>
#include <functional>

class Base;
using BasePtr = std::unique_ptr<Base>;
using ConstructFunc = std::function<BasePtr()>;

class StaticClassConstructor {
public:
    StaticClassConstructor(std::string name, const ConstructFunc& constructor);
};

class Base {
public:
    static bool make_obj(std::string type, BasePtr& ptr);
    virtual const std::string& get_name()=0;

};

