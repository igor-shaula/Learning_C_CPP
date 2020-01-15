cmake_minimum_required(VERSION 3.15)
project(Exercises_From_KR_Book C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Exercises_From_KR_Book
        chapter-1/task-1-1.c
        chapter-1/task-1-10-alt.c
        chapter-1/task-1-10.c
        chapter-1/task-1-11.c
        chapter-1/task-1-12.c
        chapter-1/task-1-13.c
        chapter-1/task-1-2.c
        chapter-1/task-1-3-float-while-header.c
        chapter-1/task-1-3-float-while.c
        chapter-1/task-1-3-int-for.c
        chapter-1/task-1-3-int-while.c
        chapter-1/task-1-4.c
        chapter-1/task-1-5-define.c
        chapter-1/task-1-5.c
        chapter-1/task-1-6.c
        chapter-1/task-1-7.c
        chapter-1/task-1-8.c
        chapter-1/task-1-9.c)
