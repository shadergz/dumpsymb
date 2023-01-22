cmake_minimum_required(VERSION 3.20)

project(dumpsymb)
find_package(PkgConfig)

#pkg_check_modules(xtext REQUIRED True)

add_executable(dumpsymb)
target_sources(dumpsymb PRIVATE dump_sym.c)

target_link_libraries(dumpsymb xtext)
