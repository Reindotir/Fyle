#pragma once
#include <iostream>
#include <vector>
#include "../utils/context.h"
#include "module.h"

#include "indexer.h"

std::vector<Module*> initModules() {
    std::vector<Module*> modules;

    context* ctx = new context();

    modules.push_back(new Indexer(*ctx));
    

    return modules;
}