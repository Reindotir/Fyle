#include "search.h"
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <cctype>
#include <sstream>

void Search::init() {

}

std::string normalize(const std::string& input) {
    std::string cleaned;

    for (char ch : input) {
        if (ch == '<' || ch == '>' || ch == ':' || ch == '"' ||
            ch == '/' || ch == '\\' || ch == '|' || ch == '?' || ch == '*') {
            cleaned += ' ';
        } else {
            cleaned += std::tolower(static_cast<unsigned char>(ch));
        }
    }
    
    std::istringstream iss(cleaned);
    std::string word, result;
    while (iss >> word) {
        if (!result.empty()) result += ' ';
        result += word;
    }

    return result;
}

std::vector<std::string> tokenize(const std::string& text) {
    std::regex word_regex(R"(\w+)");
    std::sregex_token_iterator it(text.begin(), text.end(), word_regex);
    std::sregex_token_iterator end;

    std::vector<std::string> tokens(it, end);
    
    return tokens;
}

int matches(std::string file_name, std::vector<std::string> query) {
    file_name = normalize(file_name);
    std::vector<std::string> tokens = tokenize(file_name);

    int match = 0;
    for (std::string token : query) {
        if (std::find(tokens.begin(), tokens.end(), token) != tokens.end()) {
            ++match;
        }
    }
    
    return match;
}

void search(const std::vector<std::string>& tokens, const std::shared_ptr<FileNode>& node) {
    for (const auto& child : node->children) {
        std::string name = child->name;
        
        int res = matches(name, tokens);
        if (res) {
            std::cout << res << " " << "| " << child->path << "\n";
        }

        if (child->type == "dir") {
            search(tokens, child);
        }
    }
}

void Search::run(std::vector<std::string>& args) {
    if (!args.size()) {
        std::cout << "Укажите имя файла...\n";
        return;
    }
    std::shared_ptr<FileNode> root = this->ctx.indexData;
    if (!this->ctx.indexData) {
        std::cout << "Данные еще не проиндексированы.\n";
        return;
    }

    std::string text = args[0];

    text = normalize(text);
    std::vector<std::string> tokens = tokenize(text);

    std::cout << "Поиск:\n\n";
    search(tokens, root);
    std::cout << "Поиск завершен\n\n";
}

void Search::exit() {

}

void Search::help() {
    std::cout << "\n";
    std::cout << "Что бы найти файл, вызовите:\n";
    std::cout << "  search текст\n";
    std::cout << "\n";
}