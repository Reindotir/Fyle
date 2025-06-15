#include "indexer.h"
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <ctime>
#include "../utils/context.h"
#include "../utils/FileNode.h"
#include <cstdint>
#include <filesystem>

namespace fs = std::filesystem;

void Indexer::init() {
    
}

void Indexer::run(std::vector<std::string>& args) {
    if (!args.size()) return;

    std::cout << "Индексирую...\n";

    fs::path target = args[0];
    
    if (!fs::exists(target) || !fs::is_directory(target)) {
        std::cout << "Путь не ведет к папке, котооая существует.\n";
        return
    }
    
    FileNode root = { true, target.filename(), fs::absolute(target) };
    this.ctx->indexData = root;
    
    root.lastChange = decltype(fs::last_write_time(target))::clock::to_time_t(fs::last_write_time(target));
    root.size = 0;
}

void Indexer::exit() {
    
}

void collect() {
    
}


