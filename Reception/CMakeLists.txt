project(reception_lister)

add_library(reception_lister SHARED Reception.cpp Reception.h ../Set/SET.h)

target_link_libraries(reception_lister entry)