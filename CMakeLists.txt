cmake_minimum_required(VERSION 3.10)
project(MyCoolProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(fyle
    main.cpp

    modules/modules.h
    modules/module.h


    modules/indexer.h
    modules/indexer.cpp

    modules/show.h
    modules/show.cpp

    modules/search.h
    modules/search.cpp

    modules/export.h
    modules/export.cpp

    modules/import.h
    modules/import.cpp


    utils/context.h
    utils/FileNode.h
    utils/FileNode.cpp
)
