cmake_minimum_required(VERSION 4.0)
set(CMAKE_POLICY_VERSION_MINIMUM 3.10)
project(Fyle)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(json)

add_executable(fyle
    main.cpp

    modules/module.h


    modules/indexer.cpp
    modules/show.cpp
    modules/search.cpp
    modules/export.cpp
    modules/import.cpp


    utils/FileNode.cpp
)

target_link_libraries(fyle PRIVATE nlohmann_json::nlohmann_json)