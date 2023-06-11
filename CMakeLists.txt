cmake_minimum_required(VERSION 3.02 FATAL_ERROR)
project(libtask VERSION 0.0.1 LANGUAGES C CXX)


#                     #######################################
#                         Concurrent Task Abstract Layer
#                     #######################################

message(STATUS ""                                                       )
message(STATUS "        **********************************"             )
message(STATUS "        *                                *"             )
message(STATUS "        * Concurrent Task Abstract Layer *"             )
message(STATUS "        *                ver ${PROJECT_VERSION}       *")
message(STATUS "        *                                *"             )
message(STATUS "        **********************************"             )
message(STATUS ""                                                       )


# build options
option(BUILD_STATIC   "build static library"        OFF)
option(ENABLE_TESTS   "build and run test suites"   ON)
option(BUILD_TESTS    "build test suites"           OFF)
option(RUN_TESTS      "run tests after building"    OFF)

if (ENABLE_TESTS)
    set(BUILD_TESTS ON)
    set(RUN_TESTS ON)
endif()

# Directories
set(include_dir ${CMAKE_SOURCE_DIR}/include)
set(external_dir ${CMAKE_SOURCE_DIR}/external)
set(doc_dir ${CMAKE_SOURCE_DIR}/docs)
set(cmake_module_dir ${CMAKE_SOURCE_DIR}/cmake)
set(src_dir ${CMAKE_SOURCE_DIR}/src)
set(test_dir ${CMAKE_SOURCE_DIR}/tests)

# Language standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Find libthread if neccessary
find_package(Threads REQUIRED)

set(target "${PROJECT_NAME}")

if (BUILD_TESTS)
    add_subdirectory(${test_dir})
endif()

# target_include_directories(${target} PUBLIC
#     ${src_dir}
#     ${include_dir}
#     ${external_dir}
# )

# Compile flags
if (NOT MSVC)
    set(CMAKE_C_FLAGS_DEBUG "-Og -D_DEBUG -g")
    set(CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-Og -D_DEBUG -g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
    set(CMAKE_CUDA_FLAGS_DEBUG "-g -G -D_DEBUG")
    set(CMAKE_CUDA_FLAGS_RELEASE "-DNDEBUG -O2")
endif()
