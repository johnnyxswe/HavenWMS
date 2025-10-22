#
# Core
#

set(SOURCES
vendor/stb/stb_image.h
vendor/stb/stb_image.cpp
Source/Core/Application.h
Source/Core/Application.cpp
Source/Core/Window.h
Source/Core/Window.cpp
Source/Core/Layer.h
)

add_library(Core STATIC
        Source/Core/LayerStack.cpp
        Source/Core/LayerStack.h
        Source/Core/Layer.cpp)

target_sources(Core PRIVATE ${SOURCES})

# Match VS filters to directory structure on disk
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

add_compile_definitions(
    GLFW_INCLUDE_NONE
)

target_link_libraries(Core Qt6::Core  Qt6::Widgets)
target_link_libraries(Core glm)

target_include_directories(Core PUBLIC "Source" "vendor/stb")