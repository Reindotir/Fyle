#include <iostream>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <ctime>
#include <cstdint>

struct FileNode {
    bool isDirectory;
    std::string name;
    std::string path;
    std::optional<std::weak_ptr<FileNode>> parent;
    
    std::vector<std::shared_ptr<FileNode>> children;

    std::uintmax_t size;
    std::time_t lastChange;
};