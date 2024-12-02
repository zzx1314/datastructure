include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(MergeSqList SqList.h SqList.c MergeSqList.h MergeSqList.c MergeSqList-main.c)

target_link_libraries(MergeSqList Scanf_lib)
