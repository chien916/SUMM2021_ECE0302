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


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_SOURCE_DIR = E:\SM2021\ece0302\Projects\pj3\pj3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\SM2021\ece0302\Projects\pj3\pj3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/XMLParser-tests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/XMLParser-tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/XMLParser-tests.dir/flags.make

CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.obj: CMakeFiles/XMLParser-tests.dir/flags.make
CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.obj: ../XMLParser_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\SM2021\ece0302\Projects\pj3\pj3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.obj"
	D:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\XMLParser-tests.dir\XMLParser_test.cpp.obj -c E:\SM2021\ece0302\Projects\pj3\pj3\XMLParser_test.cpp

CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.i"
	D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\SM2021\ece0302\Projects\pj3\pj3\XMLParser_test.cpp > CMakeFiles\XMLParser-tests.dir\XMLParser_test.cpp.i

CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.s"
	D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\SM2021\ece0302\Projects\pj3\pj3\XMLParser_test.cpp -o CMakeFiles\XMLParser-tests.dir\XMLParser_test.cpp.s

# Object files for target XMLParser-tests
XMLParser__tests_OBJECTS = \
"CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.obj"

# External object files for target XMLParser-tests
XMLParser__tests_EXTERNAL_OBJECTS =

XMLParser-tests.exe: CMakeFiles/XMLParser-tests.dir/XMLParser_test.cpp.obj
XMLParser-tests.exe: CMakeFiles/XMLParser-tests.dir/build.make
XMLParser-tests.exe: CMakeFiles/XMLParser-tests.dir/linklibs.rsp
XMLParser-tests.exe: CMakeFiles/XMLParser-tests.dir/objects1.rsp
XMLParser-tests.exe: CMakeFiles/XMLParser-tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\SM2021\ece0302\Projects\pj3\pj3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable XMLParser-tests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\XMLParser-tests.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/XMLParser-tests.dir/build: XMLParser-tests.exe

.PHONY : CMakeFiles/XMLParser-tests.dir/build

CMakeFiles/XMLParser-tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\XMLParser-tests.dir\cmake_clean.cmake
.PHONY : CMakeFiles/XMLParser-tests.dir/clean

CMakeFiles/XMLParser-tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\SM2021\ece0302\Projects\pj3\pj3 E:\SM2021\ece0302\Projects\pj3\pj3 E:\SM2021\ece0302\Projects\pj3\pj3\cmake-build-debug E:\SM2021\ece0302\Projects\pj3\pj3\cmake-build-debug E:\SM2021\ece0302\Projects\pj3\pj3\cmake-build-debug\CMakeFiles\XMLParser-tests.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/XMLParser-tests.dir/depend

