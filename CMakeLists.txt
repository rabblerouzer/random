cmake_minimum_required(VERSION 3.13)
project(project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(project
        buzzer.c
        buzzer.h
        led.c
        led.h
        pitches.h
        project_main.c
        state_machine.c
        state_machine.h
        switches.c
        switches.h
        timer.c
        timer.h)
