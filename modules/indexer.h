#pragma once
#include "module.h"
#include <string>
#include <vector>
#include "../utils/context.h"

class Indexer : public Module {
public:
    Indexer(context& ctx) : Module(ctx) { 
        command = "index";
    };

    void init() override;
    void run(std::vector<std::string>& args) override;
    void exit() override;
};
