# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "E:\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/455AssignCookies.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/455AssignCookies.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/455AssignCookies.dir/flags.make

CMakeFiles/455AssignCookies.dir/main.cpp.obj: CMakeFiles/455AssignCookies.dir/flags.make
CMakeFiles/455AssignCookies.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/455AssignCookies.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\455AssignCookies.dir\main.cpp.obj -c G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\main.cpp

CMakeFiles/455AssignCookies.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/455AssignCookies.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\main.cpp > CMakeFiles\455AssignCookies.dir\main.cpp.i

CMakeFiles/455AssignCookies.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/455AssignCookies.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\main.cpp -o CMakeFiles\455AssignCookies.dir\main.cpp.s

CMakeFiles/455AssignCookies.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/455AssignCookies.dir/main.cpp.obj.requires

CMakeFiles/455AssignCookies.dir/main.cpp.obj.provides: CMakeFiles/455AssignCookies.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\455AssignCookies.dir\build.make CMakeFiles/455AssignCookies.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/455AssignCookies.dir/main.cpp.obj.provides

CMakeFiles/455AssignCookies.dir/main.cpp.obj.provides.build: CMakeFiles/455AssignCookies.dir/main.cpp.obj


# Object files for target 455AssignCookies
455AssignCookies_OBJECTS = \
"CMakeFiles/455AssignCookies.dir/main.cpp.obj"

# External object files for target 455AssignCookies
455AssignCookies_EXTERNAL_OBJECTS =

455AssignCookies.exe: CMakeFiles/455AssignCookies.dir/main.cpp.obj
455AssignCookies.exe: CMakeFiles/455AssignCookies.dir/build.make
455AssignCookies.exe: CMakeFiles/455AssignCookies.dir/linklibs.rsp
455AssignCookies.exe: CMakeFiles/455AssignCookies.dir/objects1.rsp
455AssignCookies.exe: CMakeFiles/455AssignCookies.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 455AssignCookies.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\455AssignCookies.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/455AssignCookies.dir/build: 455AssignCookies.exe

.PHONY : CMakeFiles/455AssignCookies.dir/build

CMakeFiles/455AssignCookies.dir/requires: CMakeFiles/455AssignCookies.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/455AssignCookies.dir/requires

CMakeFiles/455AssignCookies.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\455AssignCookies.dir\cmake_clean.cmake
.PHONY : CMakeFiles/455AssignCookies.dir/clean

CMakeFiles/455AssignCookies.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\cmake-build-debug G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\cmake-build-debug G:\WorkingProjects\cppProjects\leetcode\my-leetcode\455AssignCookies\cmake-build-debug\CMakeFiles\455AssignCookies.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/455AssignCookies.dir/depend

