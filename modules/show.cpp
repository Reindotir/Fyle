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

    // Отступы для красивого дерева
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }

    // Вывод инфы
    std::cout << "|-- " << node->name;
    if (node->type == "file") {
        std::cout << " (" << node->size << " bytes)";
    }
    std::cout << "\n";

    // Рекурсия по детям
    for (const auto& child : node->children) {
        print(child, depth + 1);
    }
}

void Show::run(std::vector<std::string>& args) {
    auto root = this->ctx.indexData;
    if (!root) {
        std::cout << "Данные еще не проиндексированы.\n";
        return;
    }

    try {
        print(*root);
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    } catch(const std::string& e) {
        std::cout << "Ошибка: " << e << "\n";
    } catch (...) {
        std::cout << "Неизвестная ошибка!" << "\n";
    }
}

void Show::exit() {

}

void Show::help() {

}
