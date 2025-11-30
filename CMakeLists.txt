cmake_minimum_required(VERSION 3.16)

project(Kursuch_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Устанавливаем флаги кодировки
if(MSVC)
    # MSVC требует явного указания UTF-8
    add_compile_options(/utf-8)
else()
    # GCC и Clang используют UTF-8 по умолчанию — ничего не нужно
    # (но можно добавить -Wall и другие флаги при желании)
endif()

add_executable(Kursuch_1 main.cpp)

include(GNUInstallDirs)
install(TARGETS Kursuch_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
