cmake_minimum_required(VERSION 3.10)
project(MyCoolProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(fyle
    main.cpp

    modules/modules.h
    modules/module.h
    modules/indexer.h
    modules/indexer.cpp

    utils/context.h
)
