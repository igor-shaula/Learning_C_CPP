cmake_minimum_required(VERSION 3.15)
project(C++Programming_Continuation)

set(CMAKE_CXX_STANDARD 14)

add_executable(_1_AdvancedFeatures
        _1_AdvancedFeatures/Task_Header2.cpp)
add_executable(_2_NewFeaturesOf11And14
        _2_NewFeaturesOf11And14/MoveInsteadCopy.cpp)
add_executable(_3_StandardTemplateLibrary
        _3_StandardTemplateLibrary/ModifyingAlgorithms.cpp)
add_executable(_4_ErrorProcessing
        _4_ErrorProcessing/Test_ConstructorDestructor.cpp)