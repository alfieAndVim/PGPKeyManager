cmake_minimum_required(VERSION 3.0.0)
project(PGPKeyManager VERSION 0.1.0)

include(CTest)
enable_testing()

find_library(gpgme gpgme)
find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${GPGME_INCLUDE_DIRS})
link_directories(${GPGME_LIBRARY_DIRS})


file(GLOB SOURCES "src/*.cpp")

add_executable(PGPKeyManager ${SOURCES})

target_link_libraries(PGPKeyManager ${wxWidgets_LIBRARIES} ${GPGME_LIBRARIES} gpgme gpgme)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
