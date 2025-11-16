cmake_minimum_required(VERSION 3.31.6)
project(CodeSender)
find_package(cpr REQUIRED)
if(NOT cpr_FOUND)
  message("No cpr")
  include(FetchContent)
  FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.12.0) # Replace with your desired version from: https://github.com/libcpr/cpr/releases
  FetchContent_MakeAvailable(cpr)
endif()
add_executable(CodeSender)
target_link_libraries(CodeSender PRIVATE cpr::cpr)
target_sources(CodeSender
  PRIVATE
    main.cpp
)
