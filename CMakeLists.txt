cmake_minimum_required(VERSION 3.16.0)
project(Spark VERSION 0.1.0)
set (CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

#---------ADD SOURCE AND HEADER FILES ---------------
set(SOURCE_FILE_NAMES
    AdvancedBox
    CollisionBox
    TextRenderer
    Button
    Dropdown
    Editor
    EditorSidebar
    Enemy
    Entity 
    Game 
    GameState 
    ISprite 
    LevelReader
    Menu 
    Player
    PlayerFalling
    PlayerJumping
    PlayerOnGround
    PlayerState
    PlayerState
    PlayState
    Spark
    Tile 
    VisualTile
    main
)

list(TRANSFORM SOURCE_FILE_NAMES APPEND ".cpp")
list(TRANSFORM SOURCE_FILE_NAMES PREPEND "src/src/")


set(HEADER_FILE_NAMES
    AdvancedBox
    CollisionBox
    TextRenderer
    Button
    Dropdown
    Editor
    EditorSidebar
    Enemy
    Entity 
    Game 
    GameState 
    ISprite 
    LevelReader
    Menu 
    Player
    PlayerFalling
    PlayerJumping
    PlayerOnGround
    PlayerState
    PlayState
    Spark
    Tile 
    State
    VisualTile
)

list(TRANSFORM HEADER_FILE_NAMES APPEND ".h")
list(TRANSFORM HEADER_FILE_NAMES PREPEND "src/include/")


configure_file(SparkConfig.h.in SparkConfig.h)

add_executable(Spark ${SOURCE_FILE_NAMES} ${HEADER_FILE_NAMES})

target_include_directories(Spark PRIVATE ${PROJECT_SOURCE_DIR}/src/include/)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})


#-----------------------------------------------------
#---------ADD SFML LIBRARY----------------------------

add_subdirectory(libs/SFML)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/libs/SFML/)
target_include_directories(Spark PRIVATE ${PROJECT_SOURCE_DIR}/libs/SFML/include/)

find_package(SFML 2.5.1
COMPONENTS 
system window graphics network audio REQUIRED NO_DEFAULT_PATH)


target_link_libraries(Spark sfml-graphics sfml-audio)

 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
