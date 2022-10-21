cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("vulkan-tutorial" LANGUAGES CXX)

# default compiler options and warnings
include(cmake/DefaultCompilerOptionsAndWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)

# Set project directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/${CMAKE_GENERATOR_PLATFORM}/${CMAKE_BUILD_TYPE})

# Find necessary libs
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

set(APP_NAME "tutapp")
add_executable(${APP_NAME} "")
add_subdirectory(src)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_compile_features(${APP_NAME} PUBLIC cxx_std_20)
target_compile_options(${APP_NAME} PRIVATE ${SANITIZER_FLAGS} ${DEFAULT_COMPILER_OPTIONS_AND_WARNINGS})

target_include_directories(
    ${APP_NAME} PRIVATE
    "src"
)

target_link_libraries(
    ${APP_NAME} PRIVATE
    ${SANITIZER_FLAGS}
    Vulkan::Vulkan
    glfw
    glm::glm
    fmt::fmt-header-only
    spdlog::spdlog_header_only
)
