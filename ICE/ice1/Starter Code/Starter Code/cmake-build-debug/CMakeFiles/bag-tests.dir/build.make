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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bag-tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bag-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bag-tests.dir/flags.make

CMakeFiles/bag-tests.dir/bag_tests.cpp.obj: CMakeFiles/bag-tests.dir/flags.make
CMakeFiles/bag-tests.dir/bag_tests.cpp.obj: ../bag_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bag-tests.dir/bag_tests.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\bag-tests.dir\bag_tests.cpp.obj -c "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\bag_tests.cpp"

CMakeFiles/bag-tests.dir/bag_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bag-tests.dir/bag_tests.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\bag_tests.cpp" > CMakeFiles\bag-tests.dir\bag_tests.cpp.i

CMakeFiles/bag-tests.dir/bag_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bag-tests.dir/bag_tests.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\bag_tests.cpp" -o CMakeFiles\bag-tests.dir\bag_tests.cpp.s

# Object files for target bag-tests
bag__tests_OBJECTS = \
"CMakeFiles/bag-tests.dir/bag_tests.cpp.obj"

# External object files for target bag-tests
bag__tests_EXTERNAL_OBJECTS =

bag-tests.exe: CMakeFiles/bag-tests.dir/bag_tests.cpp.obj
bag-tests.exe: CMakeFiles/bag-tests.dir/build.make
bag-tests.exe: CMakeFiles/bag-tests.dir/linklibs.rsp
bag-tests.exe: CMakeFiles/bag-tests.dir/objects1.rsp
bag-tests.exe: CMakeFiles/bag-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bag-tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bag-tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bag-tests.dir/build: bag-tests.exe

.PHONY : CMakeFiles/bag-tests.dir/build

CMakeFiles/bag-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bag-tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bag-tests.dir/clean

CMakeFiles/bag-tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code" "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code" "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\ICE\ice1\Starter Code\Starter Code\cmake-build-debug\CMakeFiles\bag-tests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bag-tests.dir/depend

