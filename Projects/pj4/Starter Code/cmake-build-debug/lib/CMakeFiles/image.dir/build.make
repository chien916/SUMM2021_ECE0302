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

# Include any dependencies generated for this target.
include lib/CMakeFiles/image.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/image.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/image.dir/flags.make

lib/CMakeFiles/image.dir/image.cpp.obj: lib/CMakeFiles/image.dir/flags.make
lib/CMakeFiles/image.dir/image.cpp.obj: lib/CMakeFiles/image.dir/includes_CXX.rsp
lib/CMakeFiles/image.dir/image.cpp.obj: ../lib/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/image.dir/image.cpp.obj"
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && D:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\image.dir\image.cpp.obj -c "E:\SM2021\ece0302\Projects\pj4\Starter Code\lib\image.cpp"

lib/CMakeFiles/image.dir/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/image.cpp.i"
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SM2021\ece0302\Projects\pj4\Starter Code\lib\image.cpp" > CMakeFiles\image.dir\image.cpp.i

lib/CMakeFiles/image.dir/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/image.cpp.s"
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SM2021\ece0302\Projects\pj4\Starter Code\lib\image.cpp" -o CMakeFiles\image.dir\image.cpp.s

lib/CMakeFiles/image.dir/lodepng.cpp.obj: lib/CMakeFiles/image.dir/flags.make
lib/CMakeFiles/image.dir/lodepng.cpp.obj: lib/CMakeFiles/image.dir/includes_CXX.rsp
lib/CMakeFiles/image.dir/lodepng.cpp.obj: ../lib/lodepng.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/image.dir/lodepng.cpp.obj"
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && D:\MinGW\bin\mingw32-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\image.dir\lodepng.cpp.obj -c "E:\SM2021\ece0302\Projects\pj4\Starter Code\lib\lodepng.cpp"

lib/CMakeFiles/image.dir/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/image.dir/lodepng.cpp.i"
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SM2021\ece0302\Projects\pj4\Starter Code\lib\lodepng.cpp" > CMakeFiles\image.dir\lodepng.cpp.i

lib/CMakeFiles/image.dir/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/image.dir/lodepng.cpp.s"
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && D:\MinGW\bin\mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SM2021\ece0302\Projects\pj4\Starter Code\lib\lodepng.cpp" -o CMakeFiles\image.dir\lodepng.cpp.s

# Object files for target image
image_OBJECTS = \
"CMakeFiles/image.dir/image.cpp.obj" \
"CMakeFiles/image.dir/lodepng.cpp.obj"

# External object files for target image
image_EXTERNAL_OBJECTS =

lib/libimage.a: lib/CMakeFiles/image.dir/image.cpp.obj
lib/libimage.a: lib/CMakeFiles/image.dir/lodepng.cpp.obj
lib/libimage.a: lib/CMakeFiles/image.dir/build.make
lib/libimage.a: lib/CMakeFiles/image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libimage.a"
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && $(CMAKE_COMMAND) -P CMakeFiles\image.dir\cmake_clean_target.cmake
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\image.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/image.dir/build: lib/libimage.a

.PHONY : lib/CMakeFiles/image.dir/build

lib/CMakeFiles/image.dir/clean:
	cd /d E:\SM2021\ece0302\Projects\pj4\STARTE~1\CMAKE-~1\lib && $(CMAKE_COMMAND) -P CMakeFiles\image.dir\cmake_clean.cmake
.PHONY : lib/CMakeFiles/image.dir/clean

lib/CMakeFiles/image.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SM2021\ece0302\Projects\pj4\Starter Code" "E:\SM2021\ece0302\Projects\pj4\Starter Code\lib" "E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug" "E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug\lib" "E:\SM2021\ece0302\Projects\pj4\Starter Code\cmake-build-debug\lib\CMakeFiles\image.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/CMakeFiles/image.dir/depend

