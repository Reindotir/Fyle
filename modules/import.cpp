#include "import.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "../utils/FileNode.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void Import::init() {

}

std::shared_ptr<FileNode> deserializeNode(const json& data, std::weak_ptr<FileNode> parent = {}) {
    auto node = std::make_shared<FileNode>();
    node->type = data["type"];
    node->name = data["name"];
    node->path = data["path"];
    node->size = data["size"];
    node->lastChange = data["lastChange"];
    node->parent = parent;

    for (const auto& childJson : data["children"]) {
        auto childNode = deserializeNode(childJson, node);
        node->children.push_back(childNode);
    }

    return node;
}

std::shared_ptr<FileNode> load(const std::string& path) {
    std::ifstream in(path);
    json data;
    in >> data;
    return deserializeNode(data);
}

void Import::run(std::vector<std::string>& args) {
    if (!args.size()) {
        std::cout << "Укажите путь к файлу...\n";
        return;
    }

    std::cout << "Импортирую\n";

    std::string path = args[0];
    this->ctx.indexData = load(path);

    std::cout << "Импорт завершен\n\n";
}

void Import::exit() {

}

void Import::help() {
    std::cout << "\n";
    std::cout << "Что бы импортировать индексируемые данные в формате json, вызовите:\n";
    std::cout << "  import путь_к_файлу\n";
    std::cout << "\n";
}