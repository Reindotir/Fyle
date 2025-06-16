#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <ctime>
#include <cstdint>
#include <filesystem>

namespace fs = std::filesystem;

struct FileNode {
    std::string type;
    std::string name;
    std::string path;
    std::optional<std::weak_ptr<FileNode>> parent;
    
    std::vector<std::shared_ptr<FileNode>> children;

    std::uintmax_t size;
    std::time_t lastChange;
};

FileNode File(const fs::path& target);
std::time_t lastWriteTime(const fs::path& filePath);

