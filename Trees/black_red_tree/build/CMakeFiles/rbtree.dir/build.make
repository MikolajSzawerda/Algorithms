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
include CMakeFiles/rbtree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rbtree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rbtree.dir/flags.make

CMakeFiles/rbtree.dir/main.cpp.o: CMakeFiles/rbtree.dir/flags.make
CMakeFiles/rbtree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rbtree.dir/main.cpp.o"
	/bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rbtree.dir/main.cpp.o -c /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/main.cpp

CMakeFiles/rbtree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rbtree.dir/main.cpp.i"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/main.cpp > CMakeFiles/rbtree.dir/main.cpp.i

CMakeFiles/rbtree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rbtree.dir/main.cpp.s"
	/bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/main.cpp -o CMakeFiles/rbtree.dir/main.cpp.s

# Object files for target rbtree
rbtree_OBJECTS = \
"CMakeFiles/rbtree.dir/main.cpp.o"

# External object files for target rbtree
rbtree_EXTERNAL_OBJECTS =

rbtree: CMakeFiles/rbtree.dir/main.cpp.o
rbtree: CMakeFiles/rbtree.dir/build.make
rbtree: CMakeFiles/rbtree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rbtree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rbtree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rbtree.dir/build: rbtree

.PHONY : CMakeFiles/rbtree.dir/build

CMakeFiles/rbtree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rbtree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rbtree.dir/clean

CMakeFiles/rbtree.dir/depend:
	cd /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build /home/mszawerd/Studia/SEM2/AISDI/Algorithms/Trees/black_red_tree/build/CMakeFiles/rbtree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rbtree.dir/depend

