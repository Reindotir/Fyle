#include "FileNode.h"
#include <iostream>
#include <string>
#include <memory>
#include <optional>
#include <vector>
#include <ctime>
#include <cstdint>
#include <filesystem>

std::time_t lastWriteTime(const fs::path& filePath) {
    auto ftime = fs::last_write_time(filePath);
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now()
    );
    return std::chrono::system_clock::to_time_t(sctp);
}

FileNode File(const fs::path& target) {
    std::string type = "none";
    if (fs::is_regular_file(target)) {
        type = "file";
    } else if (fs::is_directory(target)) {
        type = "dir";
    } else if (fs::is_symlink(target)) {
        type = "link";
    } else if (fs::is_socket(target)) {
        type = "socket";
    } else if (fs::is_fifo(target)) {
        type = "fifo";
    } else if (fs::is_block_file(target)) {
        type = "block";
    } else if (fs::is_character_file(target)) {
        type = "char";
    }
    
    FileNode file = { type, target.filename().string(), fs::absolute(target).string() };
    
    if (file.type == "file") {
        file.size = fs::file_size(target);
    }
    if (file.type == "file" || file.type == "dir") {
        file.lastChange = lastWriteTime(target);
    }
    return file;
}