add_executable(1_13
    "main.cpp"
    "figure.cpp"
    "hexagon.cpp" 
    "octagon.cpp" 
    "triangle.cpp")

target_include_directories(1_13 PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)