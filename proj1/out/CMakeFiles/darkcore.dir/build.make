# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ics46/projects/proj1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ics46/projects/proj1/out

# Include any dependencies generated for this target.
include CMakeFiles/darkcore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/darkcore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/darkcore.dir/flags.make

CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.o: CMakeFiles/darkcore.dir/flags.make
CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.o: ../core/HericMazeGenerator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics46/projects/proj1/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.o -c /home/ics46/projects/proj1/core/HericMazeGenerator.cpp

CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics46/projects/proj1/core/HericMazeGenerator.cpp > CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.i

CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics46/projects/proj1/core/HericMazeGenerator.cpp -o CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.s

CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.o: CMakeFiles/darkcore.dir/flags.make
CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.o: ../core/HericMazeSolver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics46/projects/proj1/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.o -c /home/ics46/projects/proj1/core/HericMazeSolver.cpp

CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics46/projects/proj1/core/HericMazeSolver.cpp > CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.i

CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics46/projects/proj1/core/HericMazeSolver.cpp -o CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.s

CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.o: CMakeFiles/darkcore.dir/flags.make
CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.o: ../core/MazeGeneratorDFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics46/projects/proj1/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.o -c /home/ics46/projects/proj1/core/MazeGeneratorDFS.cpp

CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics46/projects/proj1/core/MazeGeneratorDFS.cpp > CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.i

CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics46/projects/proj1/core/MazeGeneratorDFS.cpp -o CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.s

CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.o: CMakeFiles/darkcore.dir/flags.make
CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.o: ../core/MazeSolverDFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics46/projects/proj1/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.o -c /home/ics46/projects/proj1/core/MazeSolverDFS.cpp

CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics46/projects/proj1/core/MazeSolverDFS.cpp > CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.i

CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics46/projects/proj1/core/MazeSolverDFS.cpp -o CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.s

# Object files for target darkcore
darkcore_OBJECTS = \
"CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.o" \
"CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.o" \
"CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.o" \
"CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.o"

# External object files for target darkcore
darkcore_EXTERNAL_OBJECTS =

lib/libdarkcore.a: CMakeFiles/darkcore.dir/core/HericMazeGenerator.cpp.o
lib/libdarkcore.a: CMakeFiles/darkcore.dir/core/HericMazeSolver.cpp.o
lib/libdarkcore.a: CMakeFiles/darkcore.dir/core/MazeGeneratorDFS.cpp.o
lib/libdarkcore.a: CMakeFiles/darkcore.dir/core/MazeSolverDFS.cpp.o
lib/libdarkcore.a: CMakeFiles/darkcore.dir/build.make
lib/libdarkcore.a: CMakeFiles/darkcore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ics46/projects/proj1/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library lib/libdarkcore.a"
	$(CMAKE_COMMAND) -P CMakeFiles/darkcore.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/darkcore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/darkcore.dir/build: lib/libdarkcore.a

.PHONY : CMakeFiles/darkcore.dir/build

CMakeFiles/darkcore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/darkcore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/darkcore.dir/clean

CMakeFiles/darkcore.dir/depend:
	cd /home/ics46/projects/proj1/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ics46/projects/proj1 /home/ics46/projects/proj1 /home/ics46/projects/proj1/out /home/ics46/projects/proj1/out /home/ics46/projects/proj1/out/CMakeFiles/darkcore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/darkcore.dir/depend

