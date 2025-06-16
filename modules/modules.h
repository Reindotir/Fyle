#pragma once
#include <iostream>
#include <vector>
#include "../utils/context.h"
#include "module.h"

#include "indexer.h"
#include "show.h"
#include "search.h"
#include "export.h"
#include "import.h"

std::vector<Module*> initModules() {
    std::vector<Module*> modules;

    context* ctx = new context();

    modules.push_back(new Indexer(*ctx));
    modules.push_back(new Show(*ctx));
    modules.push_back(new Search(*ctx));
    modules.push_back(new Export(*ctx));
    modules.push_back(new Import(*ctx));

    return modules;
}