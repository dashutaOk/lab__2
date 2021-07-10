cmake_minimum_required(VERSION 3.17)
project(lab_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_2 main.cpp DynamicArray.h Sequence.h ArraySequence.h LinkedList.h LinkSequence.h tests.h tests.cpp vector.h vector.cpp menu_vector.h menu_vector.cpp vector_test.h vector_test.cpp LinearForm.h LinearForm.cpp menu_LinearForm.h menu_LinearForm.cpp LinearForm_test.h LinearForm_test.cpp)