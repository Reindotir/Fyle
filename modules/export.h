#pragma once
#include "module.h"
#include <string>
#include <vector>
#include "../utils/context.h"

class Export : public Module {
public:
    Export(context& ctx) : Module(ctx) { 
        command = "export";
    };

    void init() override;
    void run(std::vector<std::string>& args) override;
    void exit() override;
    void help() override;
};
