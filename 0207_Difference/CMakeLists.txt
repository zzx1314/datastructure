include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(Difference SLinkList.h SLinkList.c Difference.h Difference.c Difference-main.c)

target_link_libraries(Difference Scanf_lib)

file(GLOB TestData TestData*.txt)
file(COPY ${TestData} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
