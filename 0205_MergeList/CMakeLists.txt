include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(MergeList LinkList.h LinkList.c MergeList.h MergeList.c MergeList-main.c)

target_link_libraries(MergeList Scanf_lib)

file(GLOB TestData TestData*.txt)

file(COPY ${TestData} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
