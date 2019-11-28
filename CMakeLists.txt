cmake_minimum_required(VERSION 3.15)
project(_Learning_C_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Apps_For_Stepik_Course)
include_directories(Apps_For_Stepik_Course/C++Programming_Base)

add_executable(_Learning_C_CPP
        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/ArrayTemplate2.cpp
        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/ArrayTemplate2.hpp)
#        Apps_For_Stepik_Course/C++Programming_Base/_3_Structs_Classes/ClassesInDynamicMemory.hpp
#        Apps_For_Stepik_Course/C++Programming_Base/_3_Structs_Classes/ClassesInDynamicMemory.cpp)
#        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/ArrayTemplate1.cpp
#        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/ArrayTemplate1.hpp)
#        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/ComplexTemplates.hpp
#        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/ComplexTemplates.cpp)
#        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/SimpleTemplates.hpp
#        Apps_For_Stepik_Course/C++Programming_Base/_6_Templates/SimpleTemplates.cpp)
#        Apps_For_Stepik_Course/C++Programming_Base/StringNested.cpp
#        Apps_For_Stepik_Course/C++Programming_Base/Singleton.cpp
#        Apps_For_Stepik_Course/C++Programming_Base/Singleton.hpp)
#        Apps_For_Stepik_Course/C++Programming_Base/ScopedPtr.cpp
#        Apps_For_Stepik_Course/C++Programming_Base/ScopedPtr.hpp)
#        Apps_For_Stepik_Course/C++Programming_Base/_5_AdditionalAbilities/SharedPtr.hpp
#        Apps_For_Stepik_Course/C++Programming_Base/_5_AdditionalAbilities/SharedPtr.cpp)
#        Apps_For_Stepik_Course/C++Programming_Base/SimplePointer.cpp
#        Apps_For_Stepik_Course/C++Programming_Base/SimplePointer.hpp)