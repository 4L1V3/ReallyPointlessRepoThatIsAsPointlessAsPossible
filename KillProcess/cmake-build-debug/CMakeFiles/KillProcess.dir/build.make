# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Ted\Coding\KillProcess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Ted\Coding\KillProcess\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KillProcess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/KillProcess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KillProcess.dir/flags.make

CMakeFiles/KillProcess.dir/main.cpp.obj: CMakeFiles/KillProcess.dir/flags.make
CMakeFiles/KillProcess.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Ted\Coding\KillProcess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KillProcess.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\KillProcess.dir\main.cpp.obj -c C:\Users\Ted\Coding\KillProcess\main.cpp

CMakeFiles/KillProcess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KillProcess.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Ted\Coding\KillProcess\main.cpp > CMakeFiles\KillProcess.dir\main.cpp.i

CMakeFiles/KillProcess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KillProcess.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Ted\Coding\KillProcess\main.cpp -o CMakeFiles\KillProcess.dir\main.cpp.s

CMakeFiles/KillProcess.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/KillProcess.dir/main.cpp.obj.requires

CMakeFiles/KillProcess.dir/main.cpp.obj.provides: CMakeFiles/KillProcess.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\KillProcess.dir\build.make CMakeFiles/KillProcess.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/KillProcess.dir/main.cpp.obj.provides

CMakeFiles/KillProcess.dir/main.cpp.obj.provides.build: CMakeFiles/KillProcess.dir/main.cpp.obj


# Object files for target KillProcess
KillProcess_OBJECTS = \
"CMakeFiles/KillProcess.dir/main.cpp.obj"

# External object files for target KillProcess
KillProcess_EXTERNAL_OBJECTS =

KillProcess.exe: CMakeFiles/KillProcess.dir/main.cpp.obj
KillProcess.exe: CMakeFiles/KillProcess.dir/build.make
KillProcess.exe: CMakeFiles/KillProcess.dir/linklibs.rsp
KillProcess.exe: CMakeFiles/KillProcess.dir/objects1.rsp
KillProcess.exe: CMakeFiles/KillProcess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Ted\Coding\KillProcess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KillProcess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\KillProcess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KillProcess.dir/build: KillProcess.exe

.PHONY : CMakeFiles/KillProcess.dir/build

CMakeFiles/KillProcess.dir/requires: CMakeFiles/KillProcess.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/KillProcess.dir/requires

CMakeFiles/KillProcess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KillProcess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/KillProcess.dir/clean

CMakeFiles/KillProcess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Ted\Coding\KillProcess C:\Users\Ted\Coding\KillProcess C:\Users\Ted\Coding\KillProcess\cmake-build-debug C:\Users\Ted\Coding\KillProcess\cmake-build-debug C:\Users\Ted\Coding\KillProcess\cmake-build-debug\CMakeFiles\KillProcess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KillProcess.dir/depend

