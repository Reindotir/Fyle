#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../utils/context.h"

class Module {
protected:
    context& ctx;

public:
    std::string command = "";

    virtual void init() {};
    virtual void run(std::vector<std::string>& args) {};
    virtual void exit() {};
    virtual void help() {};
    virtual ~Module() {}
    Module(context& ctx) : ctx(ctx) {};
};
