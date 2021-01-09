# CMakeList.txt : CMake project for AWC_Chess, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project (AWC_Chess VERSION 0.1.0)

# Add source to this project's executable.
add_executable (AWC_Chess src/main.cpp src/ChessGame.cpp)

# TODO: Add tests and install targets if needed.
