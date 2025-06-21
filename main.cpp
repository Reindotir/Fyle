#include <windows.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <optional>
#include "modules/module.h"
#include "modules/modules.h"

std::vector<std::string> getArgs(const std::string& command) {
    std::vector<std::string> result;

    std::stringstream ss(command);
    std::string word;
    while(ss >> word) {
        result.push_back(word);
    }

    return result;
}

std::optional<Module*> getModule(const std::string& name, std::vector<Module*> modules) {
    for (int i = 0; i < modules.size(); ++i) {
        Module* md = modules[i];
        if (md->command == name) {
            return md;
        }
    }

    return std::nullopt;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Это файловый менеджер с индексацией файлов. (exit - что бы выйти, help - информация о командах)\n\n";

    std::vector<Module*> modules = initModules();
    for (int i = 0; i < modules.size(); ++i) {
        try {
            modules[i]->init();
        } catch (const std::exception& e) {
            std::cout << "Ошибка инициализации: " << e.what() << "\n";
        } catch(const std::string& e) {
            std::cout << "Ошибка инициализации: " << e << "\n";
        } catch (...) {
            std::cout << "Неизвестная ошибка!" << "\n";
        }
    }

    while(true) {
        std::string command;
        std::getline(std::cin, command);
        if (command == "exit") break;
        if (command == "help") {
            for (int i = 0; i < modules.size(); ++i) {
                try {
                    modules[i]->help();
                } catch (...) {
                    std::cout << "Ошибка!" << "\n";
                }
            }
            continue;
        };
        if (command == "") continue;

        std::vector<std::string> args = getArgs(command);

        std::string name;
        name = args.front();
        args.erase(args.begin());

        std::optional<Module*> module = getModule(name, modules);
        if (!module.has_value()) {
            std::cout << "Такой команды не существует" << "\n";
            continue;
        }

        try {
            Module* md = module.value();

            md->run(args);
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        } catch(const std::string& e) {
            std::cout << "Ошибка: " << e << "\n";
        } catch (...) {
            std::cout << "Неизвестная ошибка!" << "\n";
        }
    };

    for (int i = 0; i < modules.size(); ++i) {
        try {
            modules[i]->exit();
        } catch (const std::exception& e) {
            std::cout << "Ошибка выхода: " << e.what() << "\n";
        } catch(const std::string& e) {
            std::cout << "Ошибка выхода: " << e << "\n";
        } catch (...) {
            std::cout << "Неизвестная ошибка!" << "\n";
        }
    }
    std::cout << "Поки" << "\n";
    std::cout << "Нажмите Enter что бы выйти";
    std::string temp;
    std::getline(std::cin, temp);
    return 0;
}

