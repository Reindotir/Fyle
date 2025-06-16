#pragma once
#include "module.h"
#include <string>
#include <vector>
#include "../utils/context.h"

class Import : public Module {
public:
    Import(context& ctx) : Module(ctx) { 
        command = "import";
    };

    void init() override;
    void run(std::vector<std::string>& args) override;
    void exit() override;
    void help() override;
};
