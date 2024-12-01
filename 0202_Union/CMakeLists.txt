include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(Union SqList.h SqList.c Union.h Union.c Union-main.c)

target_link_libraries(Union Scanf_lib)
