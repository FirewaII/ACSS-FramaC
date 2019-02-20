cmake_minimum_required(VERSION 3.13)
project(ACSS_FramaC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ACSS_FramaC
        array_copy.c
        disjoint_array_copy.c
        fois_2.c
        Makefile
        quotient.c
        quotient_reste.c
        read_int.c
        read_int.h
        README.txt
        write_int.c
        write_int.h)
