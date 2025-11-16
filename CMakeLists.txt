cmake_minimum_required(VERSION 3.31.6)
project(CodeSender)
find_package(cpr REQUIRED)
add_executable(CodeSender)
target_link_libraries(CodeSender PRIVATE cpr::cpr)
target_sources(CodeSender
  PRIVATE
    main.cpp
)
