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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\CP_Stuffs\CP-Algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\CP_Stuffs\CP-Algorithms\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DFS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DFS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DFS.dir/flags.make

CMakeFiles/DFS.dir/DFS.cpp.obj: CMakeFiles/DFS.dir/flags.make
CMakeFiles/DFS.dir/DFS.cpp.obj: DFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\CP_Stuffs\CP-Algorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DFS.dir/DFS.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DFS.dir\DFS.cpp.obj -c E:\CP_Stuffs\CP-Algorithms\cmake-build-debug\DFS.cpp

CMakeFiles/DFS.dir/DFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DFS.dir/DFS.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\CP_Stuffs\CP-Algorithms\cmake-build-debug\DFS.cpp > CMakeFiles\DFS.dir\DFS.cpp.i

CMakeFiles/DFS.dir/DFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DFS.dir/DFS.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\CP_Stuffs\CP-Algorithms\cmake-build-debug\DFS.cpp -o CMakeFiles\DFS.dir\DFS.cpp.s

# Object files for target DFS
DFS_OBJECTS = \
"CMakeFiles/DFS.dir/DFS.cpp.obj"

# External object files for target DFS
DFS_EXTERNAL_OBJECTS =

DFS.exe: CMakeFiles/DFS.dir/DFS.cpp.obj
DFS.exe: CMakeFiles/DFS.dir/build.make
DFS.exe: CMakeFiles/DFS.dir/linklibs.rsp
DFS.exe: CMakeFiles/DFS.dir/objects1.rsp
DFS.exe: CMakeFiles/DFS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\CP_Stuffs\CP-Algorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DFS.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DFS.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DFS.dir/build: DFS.exe

.PHONY : CMakeFiles/DFS.dir/build

CMakeFiles/DFS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DFS.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DFS.dir/clean

CMakeFiles/DFS.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\CP_Stuffs\CP-Algorithms E:\CP_Stuffs\CP-Algorithms E:\CP_Stuffs\CP-Algorithms\cmake-build-debug E:\CP_Stuffs\CP-Algorithms\cmake-build-debug E:\CP_Stuffs\CP-Algorithms\cmake-build-debug\CMakeFiles\DFS.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DFS.dir/depend

