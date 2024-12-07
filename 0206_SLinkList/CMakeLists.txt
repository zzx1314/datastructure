include_directories(${CMAKE_SOURCE_DIR}/Status)

add_executable(SLinkList SLinkList.h SLinkList.c SLinkList-main.c)

target_link_libraries(SLinkList scanf_lib)
