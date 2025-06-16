#include "export.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
#include "../utils/FileNode.h"
using json = nlohmann::json;

void Export::init() {

}

json serializeNode(const std::shared_ptr<FileNode>& node) {
    json data;
    data["type"] = node->type;
    data["name"] = node->name;
    data["path"] = node->path;
    data["size"] = node->size;
    data["lastChange"] = node->lastChange;

    data["children"] = json::array();
    for (auto& child : node->children) {
        data["children"].push_back(serializeNode(child));
    }

    return data;
}

void save(const std::shared_ptr<FileNode>& node, const std::string& output) {
    json data = serializeNode(node);
    std::ofstream out(output);
    out << data.dump(4); 
}

void Export::run(std::vector<std::string>& args) {
    if (!args.size()) {
        std::cout << "Укажите куда сохранить...\n";
        return;
    }
    std::shared_ptr<FileNode> root = this->ctx.indexData;
    if (!this->ctx.indexData) {
        std::cout << "Данные еще не проиндексированы.\n";
        return;
    }

    std::string output = args[0];

    std::cout << "Экспортирую...\n";
    save(this->ctx.indexData, output);
    std::cout << "Экспорт завершен\n\n";
}

void Export::exit() {

}

void Export::help() {
    std::cout << "\n";
    std::cout << "Что бы экспортировать индексируемые данные в формате json, вызовите:\n";
    std::cout << "  export путь_куда_сохранить_файл\n";
    std::cout << "\n";
}