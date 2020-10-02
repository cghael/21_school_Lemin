cmake_minimum_required(VERSION 3.16)
project(Lemin C)

set(CMAKE_C_STANDARD 90)

set(SOURCES sources/main.c
        sources/ft_lemin_init.c
        sources/ft_error_n_exit.c
        sources/ft_check_flags.c
        sources/ft_parse_data.c
        sources/ft_parse_ants.c
        sources/ft_get_data.c
        sources/ft_free_data.c
        sources/ft_parse_rooms.c
        sources/ft_get_last_data_node.c
        sources/ft_check_correct_room.c
        sources/ft_is_link.c
        sources/ft_create_graph.c
        sources/ft_parse_links.c
        sources/ft_free_lemin.c
        sources/ft_find_paths.c
        sources/ft_print_matrix.c
        sources/ft_set_levels.c
        sources/ft_free_tracks.c
        sources/ft_write_path.c
        sources/ft_create_new_track.c
        sources/ft_change_cross_ways.c
        sources/ft_run_ants_run.c
        sources/ft_sort_tracks.c
        sources/ft_decision_to_countinue.c
        sources/ft_ants_choose_ways.c
        sources/ft_ants_mooving.c
        sources/ft_print_steps.c
        sources/ft_write_usage_n_exit.c
        sources/ft_create_n_open_file.c
        sources/ft_you_were_warned.c
        sources/ft_run_visual.c)

add_executable(Lemin ${SOURCES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/21_school_ft_printf/includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/21_school_ft_printf/libft/inc)

add_subdirectory(21_school_ft_printf)

target_link_libraries(Lemin libftprintf)