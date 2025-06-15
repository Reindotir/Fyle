#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../utils/context.h"

class Module {
    context& ctx;

public:
    std::string command = "";

    virtual void init() {};
    virtual void run(std::vector<std::string>& args) {};
    virtual void exit() {};
    virtual ~Module() {}
    Module(context& ctx) : ctx(ctx) {};
};
