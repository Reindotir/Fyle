#include "indexer.h"
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <ctime>
#include "../utils/FileNode.h"
#include "../utils/context.h"
#include <cstdint>
#include <filesystem>

namespace fs = std::filesystem;

void Indexer::init() {
    
}

void collect(const fs::path& target, std::shared_ptr<FileNode> parent) {
    for (const auto& entry : fs::directory_iterator(target)) {
        auto child = std::make_shared<FileNode>(File(entry.path()));

        child->parent = parent;
        parent->children.push_back(child);

        if (fs::is_directory(entry)) {
            collect(entry.path(), child);
        }
    }
}

void Indexer::run(std::vector<std::string>& args) {
    if (!args.size()) {
        std::cout << "Укажите путь...\n";
        return;
    }

    std::cout << "Индексирую...\n";

    fs::path target = args[0];
    
    if (!fs::exists(target) || !fs::is_directory(target)) {
        std::cout << "Путь не ведет к папке, котороя существует.\n";
        return;
    }
    
    auto root = std::make_shared<FileNode>(File(target));
    this->ctx.indexData = root;
    collect(target, root);

    std::cout << "Индксация завершена\n";
}

void Indexer::exit() {
    
}

void Indexer::help() {
    
}

