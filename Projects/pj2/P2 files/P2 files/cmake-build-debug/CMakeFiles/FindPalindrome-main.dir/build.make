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
CMAKE_SOURCE_DIR = "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/FindPalindrome-main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FindPalindrome-main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FindPalindrome-main.dir/flags.make

CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.obj: CMakeFiles/FindPalindrome-main.dir/flags.make
CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.obj: ../FindPalindrome_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FindPalindrome-main.dir\FindPalindrome_main.cpp.obj -c "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\FindPalindrome_main.cpp"

CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\FindPalindrome_main.cpp" > CMakeFiles\FindPalindrome-main.dir\FindPalindrome_main.cpp.i

CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\FindPalindrome_main.cpp" -o CMakeFiles\FindPalindrome-main.dir\FindPalindrome_main.cpp.s

CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.obj: CMakeFiles/FindPalindrome-main.dir/flags.make
CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.obj: ../FindPalindrome.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.obj"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\FindPalindrome-main.dir\FindPalindrome.cpp.obj -c "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\FindPalindrome.cpp"

CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.i"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\FindPalindrome.cpp" > CMakeFiles\FindPalindrome-main.dir\FindPalindrome.cpp.i

CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.s"
	D:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\FindPalindrome.cpp" -o CMakeFiles\FindPalindrome-main.dir\FindPalindrome.cpp.s

# Object files for target FindPalindrome-main
FindPalindrome__main_OBJECTS = \
"CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.obj" \
"CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.obj"

# External object files for target FindPalindrome-main
FindPalindrome__main_EXTERNAL_OBJECTS =

FindPalindrome-main.exe: CMakeFiles/FindPalindrome-main.dir/FindPalindrome_main.cpp.obj
FindPalindrome-main.exe: CMakeFiles/FindPalindrome-main.dir/FindPalindrome.cpp.obj
FindPalindrome-main.exe: CMakeFiles/FindPalindrome-main.dir/build.make
FindPalindrome-main.exe: CMakeFiles/FindPalindrome-main.dir/linklibs.rsp
FindPalindrome-main.exe: CMakeFiles/FindPalindrome-main.dir/objects1.rsp
FindPalindrome-main.exe: CMakeFiles/FindPalindrome-main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable FindPalindrome-main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\FindPalindrome-main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FindPalindrome-main.dir/build: FindPalindrome-main.exe

.PHONY : CMakeFiles/FindPalindrome-main.dir/build

CMakeFiles/FindPalindrome-main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\FindPalindrome-main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/FindPalindrome-main.dir/clean

CMakeFiles/FindPalindrome-main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files" "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files" "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\cmake-build-debug" "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\cmake-build-debug" "E:\SM2021\ece0302\Projects\pj2\P2 files\P2 files\cmake-build-debug\CMakeFiles\FindPalindrome-main.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/FindPalindrome-main.dir/depend
