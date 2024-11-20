cmake_minimum_required(VERSION 3.25)
project(sdaLabBun)

set(CMAKE_CXX_STANDARD 17)

add_executable(sdaLabBun main.cpp ATM/backtracing/Backtracking.cpp ATM/backtracing/Backtracking.h ATM/atm.cpp ATM/atm.h bancnote/collectionB.cpp bancnote/collectionB.h tranzactie/tranzactie.cpp tranzactie/tranzactie.h LinkedList/node.cpp LinkedList/node.h LinkedList/list.cpp LinkedList/list.h)
