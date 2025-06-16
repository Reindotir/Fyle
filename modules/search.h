#pragma once
#include "module.h"
#include <string>
#include <vector>
#include "../utils/context.h"

class Search : public Module {
public:
    Search(context& ctx) : Module(ctx) { 
        command = "search";
    };

    void init() override;
    void run(std::vector<std::string>& args) override;
    void exit() override;
    void help() override;
};
