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
CMAKE_SOURCE_DIR = /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build

# Include any dependencies generated for this target.
include CMakeFiles/testApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testApp.dir/flags.make

CMakeFiles/testApp.dir/tests/testTree.cpp.o: CMakeFiles/testApp.dir/flags.make
CMakeFiles/testApp.dir/tests/testTree.cpp.o: ../tests/testTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testApp.dir/tests/testTree.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testApp.dir/tests/testTree.cpp.o -c /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/tests/testTree.cpp

CMakeFiles/testApp.dir/tests/testTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testApp.dir/tests/testTree.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/tests/testTree.cpp > CMakeFiles/testApp.dir/tests/testTree.cpp.i

CMakeFiles/testApp.dir/tests/testTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testApp.dir/tests/testTree.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/tests/testTree.cpp -o CMakeFiles/testApp.dir/tests/testTree.cpp.s

# Object files for target testApp
testApp_OBJECTS = \
"CMakeFiles/testApp.dir/tests/testTree.cpp.o"

# External object files for target testApp
testApp_EXTERNAL_OBJECTS =

testApp: CMakeFiles/testApp.dir/tests/testTree.cpp.o
testApp: CMakeFiles/testApp.dir/build.make
testApp: lib/libgtest_main.a
testApp: lib/libgtest.a
testApp: CMakeFiles/testApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testApp.dir/build: testApp

.PHONY : CMakeFiles/testApp.dir/build

CMakeFiles/testApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testApp.dir/clean

CMakeFiles/testApp.dir/depend:
	cd /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build/CMakeFiles/testApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testApp.dir/depend

