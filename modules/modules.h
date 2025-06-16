#pragma once
#include <iostream>
#include <vector>
#include "../utils/context.h"
#include "module.h"

#include "indexer.h"
#include "show.h"

std::vector<Module*> initModules() {
    std::vector<Module*> modules;

    context* ctx = new context();

    modules.push_back(new Indexer(*ctx));
    modules.push_back(new Show(*ctx));

    return modules;
}