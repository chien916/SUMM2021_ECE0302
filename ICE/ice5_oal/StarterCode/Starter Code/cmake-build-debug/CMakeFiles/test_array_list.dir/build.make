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
CMAKE_SOURCE_DIR = "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/test_array_list.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_array_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_array_list.dir/flags.make

CMakeFiles/test_array_list.dir/test_array_list.cpp.obj: CMakeFiles/test_array_list.dir/flags.make
CMakeFiles/test_array_list.dir/test_array_list.cpp.obj: ../test_array_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_array_list.dir/test_array_list.cpp.obj"
	D:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_array_list.dir\test_array_list.cpp.obj -c "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\test_array_list.cpp"

CMakeFiles/test_array_list.dir/test_array_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_array_list.dir/test_array_list.cpp.i"
	D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\test_array_list.cpp" > CMakeFiles\test_array_list.dir\test_array_list.cpp.i

CMakeFiles/test_array_list.dir/test_array_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_array_list.dir/test_array_list.cpp.s"
	D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\test_array_list.cpp" -o CMakeFiles\test_array_list.dir\test_array_list.cpp.s

# Object files for target test_array_list
test_array_list_OBJECTS = \
"CMakeFiles/test_array_list.dir/test_array_list.cpp.obj"

# External object files for target test_array_list
test_array_list_EXTERNAL_OBJECTS =

test_array_list.exe: CMakeFiles/test_array_list.dir/test_array_list.cpp.obj
test_array_list.exe: CMakeFiles/test_array_list.dir/build.make
test_array_list.exe: CMakeFiles/test_array_list.dir/linklibs.rsp
test_array_list.exe: CMakeFiles/test_array_list.dir/objects1.rsp
test_array_list.exe: CMakeFiles/test_array_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_array_list.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_array_list.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_array_list.dir/build: test_array_list.exe

.PHONY : CMakeFiles/test_array_list.dir/build

CMakeFiles/test_array_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_array_list.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_array_list.dir/clean

CMakeFiles/test_array_list.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code" "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code" "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\ICE\ice5_oal\StarterCode\Starter Code\cmake-build-debug\CMakeFiles\test_array_list.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_array_list.dir/depend

