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
CMAKE_SOURCE_DIR = "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/dynamic-bag-tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dynamic-bag-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dynamic-bag-tests.dir/flags.make

CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.obj: CMakeFiles/dynamic-bag-tests.dir/flags.make
CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.obj: ../dynamic_bag_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.obj"
	C:\MinGW\bin\c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\dynamic-bag-tests.dir\dynamic_bag_tests.cpp.obj -c "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\dynamic_bag_tests.cpp"

CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.i"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\dynamic_bag_tests.cpp" > CMakeFiles\dynamic-bag-tests.dir\dynamic_bag_tests.cpp.i

CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.s"
	C:\MinGW\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\dynamic_bag_tests.cpp" -o CMakeFiles\dynamic-bag-tests.dir\dynamic_bag_tests.cpp.s

# Object files for target dynamic-bag-tests
dynamic__bag__tests_OBJECTS = \
"CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.obj"

# External object files for target dynamic-bag-tests
dynamic__bag__tests_EXTERNAL_OBJECTS =

dynamic-bag-tests.exe: CMakeFiles/dynamic-bag-tests.dir/dynamic_bag_tests.cpp.obj
dynamic-bag-tests.exe: CMakeFiles/dynamic-bag-tests.dir/build.make
dynamic-bag-tests.exe: CMakeFiles/dynamic-bag-tests.dir/linklibs.rsp
dynamic-bag-tests.exe: CMakeFiles/dynamic-bag-tests.dir/objects1.rsp
dynamic-bag-tests.exe: CMakeFiles/dynamic-bag-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dynamic-bag-tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dynamic-bag-tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dynamic-bag-tests.dir/build: dynamic-bag-tests.exe

.PHONY : CMakeFiles/dynamic-bag-tests.dir/build

CMakeFiles/dynamic-bag-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dynamic-bag-tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dynamic-bag-tests.dir/clean

CMakeFiles/dynamic-bag-tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code" "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code" "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\ICE\ice4_db\Starter Code-3\Starter Code\cmake-build-debug\CMakeFiles\dynamic-bag-tests.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/dynamic-bag-tests.dir/depend

