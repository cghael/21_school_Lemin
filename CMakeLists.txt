cmake_minimum_required(VERSION 3.16)
project(Lemin C)

set(CMAKE_C_STANDARD 90)

set(SOURCES sources/main.c)

add_executable(Lemin ${SOURCES})

include_directories(includes)
include_directories(21_school_ft_printf/includes)
include_directories(21_school_ft_printf/libft/inc)

add_subdirectory(21_school_ft_printf)

target_link_libraries(Lemin libftprintf)