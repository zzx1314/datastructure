include_directories(${CMAKE_SOURCE_DIR/Status})

add_executable(LinkedList LinkList.h LinkList.c LinkList-main.c)

target_link_libraries(LinkedList Scanf_lib)

file(GLOB TestData TestData*.txt)

file(COPY ${TestData} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
