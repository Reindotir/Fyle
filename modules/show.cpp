#include "show.h"
#include <iostream>
#include <string>
#include <vector>
#include <optional>
#include <ctime>
#include "../utils/FileNode.h"
#include "../utils/context.h"

void Show::init() {

}

void print(const std::shared_ptr<FileNode>& node, int depth = 0) {
    if (!node) return;

    for (int i = 0; i < depth; ++i) {
        std::cout << "   ";
    }
    std::cout << "|-- " << node->name;
    if (node->type == "dir") {
        std::cout << "/";
    }
    if (node->type == "file") {
        std::cout << " (" << node->size << " bytes)";
    }
    std::cout << "\n";

    if (node->type != "dir") return;
    for (const auto& child : node->children) {
        print(child, depth + 1);
    }
}

void Show::run(std::vector<std::string>& args) {
    std::shared_ptr<FileNode> root = this->ctx.indexData;
    if (!this->ctx.indexData) {
        std::cout << "Данные еще не проиндексированы.\n";
        return;
    }
    std::cout << "\n";
    print(root);
    std::cout << "\n";
}

void Show::exit() {

}

void Show::help() {

}
