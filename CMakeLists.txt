cmake_minimum_required(VERSION 3.24)
project(SP_CPPBank)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SP_CPPBank
        Borrower.cpp
        Borrower.h
        Currency.cpp
        Currency.h
        Deal.cpp
        Deal.h
        Facility.cpp
        Facility.h
        Lender.cpp
        Lender.h
        main.cpp Portfolio.cpp
        Portfolio.h
        Part.cpp
        Part.h)
