#pragma once
#include "FileNode.h"
#include <iostream>
#include <memory>

struct context {
    std::shared_ptr<FileNode>* indexData;
    
};