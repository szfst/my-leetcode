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
CMAKE_SOURCE_DIR = G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/131PalindromePartitioning.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/131PalindromePartitioning.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/131PalindromePartitioning.dir/flags.make

CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj: CMakeFiles/131PalindromePartitioning.dir/flags.make
CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\131PalindromePartitioning.dir\main.cpp.obj -c G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\main.cpp

CMakeFiles/131PalindromePartitioning.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/131PalindromePartitioning.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\main.cpp > CMakeFiles\131PalindromePartitioning.dir\main.cpp.i

CMakeFiles/131PalindromePartitioning.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/131PalindromePartitioning.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\main.cpp -o CMakeFiles\131PalindromePartitioning.dir\main.cpp.s

CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.requires

CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.provides: CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\131PalindromePartitioning.dir\build.make CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.provides

CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.provides.build: CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj


# Object files for target 131PalindromePartitioning
131PalindromePartitioning_OBJECTS = \
"CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj"

# External object files for target 131PalindromePartitioning
131PalindromePartitioning_EXTERNAL_OBJECTS =

131PalindromePartitioning.exe: CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj
131PalindromePartitioning.exe: CMakeFiles/131PalindromePartitioning.dir/build.make
131PalindromePartitioning.exe: CMakeFiles/131PalindromePartitioning.dir/linklibs.rsp
131PalindromePartitioning.exe: CMakeFiles/131PalindromePartitioning.dir/objects1.rsp
131PalindromePartitioning.exe: CMakeFiles/131PalindromePartitioning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 131PalindromePartitioning.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\131PalindromePartitioning.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/131PalindromePartitioning.dir/build: 131PalindromePartitioning.exe

.PHONY : CMakeFiles/131PalindromePartitioning.dir/build

CMakeFiles/131PalindromePartitioning.dir/requires: CMakeFiles/131PalindromePartitioning.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/131PalindromePartitioning.dir/requires

CMakeFiles/131PalindromePartitioning.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\131PalindromePartitioning.dir\cmake_clean.cmake
.PHONY : CMakeFiles/131PalindromePartitioning.dir/clean

CMakeFiles/131PalindromePartitioning.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\cmake-build-debug G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\cmake-build-debug G:\WorkingProjects\cppProjects\leetcode\my-leetcode\131PalindromePartitioning\cmake-build-debug\CMakeFiles\131PalindromePartitioning.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/131PalindromePartitioning.dir/depend

