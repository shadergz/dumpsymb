cmake_minimum_required(VERSION 3.20)

project(dsym)
find_package(PkgConfig)

pkg_check_modules(bin REQUIRED bin)

add_executable(dsym dsym.c)

target_link_libraries(dsym bin)
