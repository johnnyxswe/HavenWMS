#
# Dependencies
#
include (FetchContent)

# Qt
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
set_target_properties(Qt6::Core Qt6::Widgets PROPERTIES FOLDER "Dependencies")
# Or for Qt5: find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

# GLM
FetchContent_Declare(
        glm
        GIT_REPOSITORY "https://github.com/g-truc/glm.git"
        GIT_TAG "1.0.1"
        GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(glm)
set_target_properties(glm PROPERTIES FOLDER "Dependencies")

FetchContent_Declare(
        assimp
        GIT_REPOSITORY https://github.com/assimp/assimp.git
        GIT_TAG master
        GIT_SHALLOW TRUE
)