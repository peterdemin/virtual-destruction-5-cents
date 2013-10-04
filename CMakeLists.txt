cmake_minimum_required(VERSION 2.8)

project(virtual_destruction_5_cents CXX)

set(
    sources
    ./main.cpp
)

set(
    headers
    ./scenario1.h
    ./scenario2.h
    ./scenario3.h
    ./scenario4.h
    ./scenario5.h
)

add_executable(
     virtual_destruction_5_cents
     ${sources}
     ${headers}
)
