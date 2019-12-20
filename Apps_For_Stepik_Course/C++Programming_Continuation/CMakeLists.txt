cmake_minimum_required(VERSION 3.15)
project(C++Programming_Continuation)

set(CMAKE_CXX_STANDARD 14)

add_executable(_1_AdvancedFeatures
        _1_AdvancedFeatures/Task_ManBearPig.cpp _1_AdvancedFeatures/Typedefs.cpp _1_AdvancedFeatures/Listener.cpp)
add_executable(_2_NewFeaturesOf11And14
        _2_NewFeaturesOf11And14/NewEnums.cpp)