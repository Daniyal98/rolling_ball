cmake_minimum_required(VERSION 3.15)
project(rolling_ball)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")


add_executable(rolling_ball rolling_ball.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW 2.0 REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(rolling_ball GLEW::GLEW ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})