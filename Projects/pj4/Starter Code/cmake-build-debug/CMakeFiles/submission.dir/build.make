# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\SM2021\ece0302\Projects\pj4\Starter Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug"

# Utility rule file for submission.

# Include the progress variables for this target.
include CMakeFiles/submission.dir/progress.make

CMakeFiles/submission:
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1 && "D:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E tar cfv "E:/SM2021/ece0302/Projects/pj4/Starter Code/cmake-build-debug/submission.zip" --format=zip deque.hpp deque.tpp test_deque.cpp pathfinder.cpp

submission: CMakeFiles/submission
submission: CMakeFiles/submission.dir/build.make

.PHONY : submission

# Rule to build all files generated by this target.
CMakeFiles/submission.dir/build: submission

.PHONY : CMakeFiles/submission.dir/build

CMakeFiles/submission.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\submission.dir\cmake_clean.cmake
.PHONY : CMakeFiles/submission.dir/clean

CMakeFiles/submission.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SM2021\ece0302\Projects\pj4\Starter Code" "E:\SM2021\ece0302\Projects\pj4\Starter Code" "E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug\CMakeFiles\submission.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/submission.dir/depend

