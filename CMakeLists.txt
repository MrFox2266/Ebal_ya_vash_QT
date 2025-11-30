cmake_minimum_required(VERSION 3.16)

project(Kursuch_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure console application for Windows
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mconsole")
endif()

# For Qt environments, ensure proper console handling
set(CMAKE_WIN32_EXECUTABLE OFF)

add_executable(Kursuch_1 main.cpp)

# Set properties to ensure proper console behavior
set_target_properties(Kursuch_1 PROPERTIES
    WIN32_EXECUTABLE FALSE
    MACOSX_BUNDLE FALSE
)

include(GNUInstallDirs)
install(TARGETS Kursuch_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
