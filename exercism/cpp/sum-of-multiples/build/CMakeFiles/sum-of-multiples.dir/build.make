# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build

# Include any dependencies generated for this target.
include CMakeFiles/sum-of-multiples.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sum-of-multiples.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sum-of-multiples.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sum-of-multiples.dir/flags.make

CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o: CMakeFiles/sum-of-multiples.dir/flags.make
CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o: ../sum_of_multiples_test.cpp
CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o: CMakeFiles/sum-of-multiples.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o -MF CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o.d -o CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o -c /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/sum_of_multiples_test.cpp

CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/sum_of_multiples_test.cpp > CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.i

CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/sum_of_multiples_test.cpp -o CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.s

CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o: CMakeFiles/sum-of-multiples.dir/flags.make
CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o: ../sum_of_multiples.cpp
CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o: CMakeFiles/sum-of-multiples.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o -MF CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o.d -o CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o -c /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/sum_of_multiples.cpp

CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/sum_of_multiples.cpp > CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.i

CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/sum_of_multiples.cpp -o CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.s

CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o: CMakeFiles/sum-of-multiples.dir/flags.make
CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o: ../test/tests-main.cpp
CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o: CMakeFiles/sum-of-multiples.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o -MF CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o.d -o CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o -c /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/test/tests-main.cpp

CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/test/tests-main.cpp > CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.i

CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/test/tests-main.cpp -o CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.s

# Object files for target sum-of-multiples
sum__of__multiples_OBJECTS = \
"CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o" \
"CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o" \
"CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o"

# External object files for target sum-of-multiples
sum__of__multiples_EXTERNAL_OBJECTS =

sum-of-multiples: CMakeFiles/sum-of-multiples.dir/sum_of_multiples_test.cpp.o
sum-of-multiples: CMakeFiles/sum-of-multiples.dir/sum_of_multiples.cpp.o
sum-of-multiples: CMakeFiles/sum-of-multiples.dir/test/tests-main.cpp.o
sum-of-multiples: CMakeFiles/sum-of-multiples.dir/build.make
sum-of-multiples: CMakeFiles/sum-of-multiples.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable sum-of-multiples"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sum-of-multiples.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sum-of-multiples.dir/build: sum-of-multiples
.PHONY : CMakeFiles/sum-of-multiples.dir/build

CMakeFiles/sum-of-multiples.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sum-of-multiples.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sum-of-multiples.dir/clean

CMakeFiles/sum-of-multiples.dir/depend:
	cd /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build /home/anthony/repos/github.com/exercism/cpp/sum-of-multiples/build/CMakeFiles/sum-of-multiples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sum-of-multiples.dir/depend

