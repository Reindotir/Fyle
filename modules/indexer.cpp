#include "indexer.h"
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <ctime>
#include "../utils/context.h"
#include <cstdint>

void Indexer::init() {
    
}

void Indexer::run(std::vector<std::string>& args) {
    if (!args.size()) return;

    std::cout << "Индексирую...\n";

    std::string path = args[0];

}

void Indexer::exit() {
    
}

struct FileNode {
    std::string name;
    std::string path;
    std::optional<FileNode*> parent;

    bool isDirectory;
    std::vector<FileNode*> children;

    std::uintmax_t size;
    std::time_t lastChange;
};

