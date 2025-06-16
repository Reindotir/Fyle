#pragma once
#include "module.h"
#include <string>
#include <vector>
#include "../utils/context.h"

class Show : public Module {
public:
    Show(context& ctx) : Module(ctx) { 
        command = "show";
    };

    void init() override;
    void run(std::vector<std::string>& args) override;
    void exit() override;
    void help() override;
};
