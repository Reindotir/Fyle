cmake_minimum_required(VERSION 3.20)
project(Fyle)

set(CMAKE_CXX_STANDARD 17)

find_package(nlohmann_json CONFIG REQUIRED)

add_executable(Fyle
    main.cpp

    modules/module.h

    modules/indexer.cpp
    modules/show.cpp
    modules/search.cpp
    modules/export.cpp
    modules/import.cpp

    utils/FileNode.cpp
)

target_include_directories(Fyle PRIVATE C:/dev/vcpkg/installed/x64-windows/include)
target_link_directories(Fyle PRIVATE C:/dev/vcpkg/installed/x64-windows/lib)
target_link_libraries(Fyle PRIVATE
nlohmann_json::nlohmann_json
boost_locale
)