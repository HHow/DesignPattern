# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++

# Include any dependencies generated for this target.
include Component/CMakeFiles/Component.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Component/CMakeFiles/Component.dir/compiler_depend.make

# Include the progress variables for this target.
include Component/CMakeFiles/Component.dir/progress.make

# Include the compile flags for this target's objects.
include Component/CMakeFiles/Component.dir/flags.make

Component/CMakeFiles/Component.dir/src/Map.cpp.o: Component/CMakeFiles/Component.dir/flags.make
Component/CMakeFiles/Component.dir/src/Map.cpp.o: Component/src/Map.cpp
Component/CMakeFiles/Component.dir/src/Map.cpp.o: Component/CMakeFiles/Component.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Component/CMakeFiles/Component.dir/src/Map.cpp.o"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Component/CMakeFiles/Component.dir/src/Map.cpp.o -MF CMakeFiles/Component.dir/src/Map.cpp.o.d -o CMakeFiles/Component.dir/src/Map.cpp.o -c /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/Map.cpp

Component/CMakeFiles/Component.dir/src/Map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Component.dir/src/Map.cpp.i"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/Map.cpp > CMakeFiles/Component.dir/src/Map.cpp.i

Component/CMakeFiles/Component.dir/src/Map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Component.dir/src/Map.cpp.s"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/Map.cpp -o CMakeFiles/Component.dir/src/Map.cpp.s

Component/CMakeFiles/Component.dir/src/Unit.cpp.o: Component/CMakeFiles/Component.dir/flags.make
Component/CMakeFiles/Component.dir/src/Unit.cpp.o: Component/src/Unit.cpp
Component/CMakeFiles/Component.dir/src/Unit.cpp.o: Component/CMakeFiles/Component.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Component/CMakeFiles/Component.dir/src/Unit.cpp.o"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Component/CMakeFiles/Component.dir/src/Unit.cpp.o -MF CMakeFiles/Component.dir/src/Unit.cpp.o.d -o CMakeFiles/Component.dir/src/Unit.cpp.o -c /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/Unit.cpp

Component/CMakeFiles/Component.dir/src/Unit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Component.dir/src/Unit.cpp.i"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/Unit.cpp > CMakeFiles/Component.dir/src/Unit.cpp.i

Component/CMakeFiles/Component.dir/src/Unit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Component.dir/src/Unit.cpp.s"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/Unit.cpp -o CMakeFiles/Component.dir/src/Unit.cpp.s

Component/CMakeFiles/Component.dir/src/User.cpp.o: Component/CMakeFiles/Component.dir/flags.make
Component/CMakeFiles/Component.dir/src/User.cpp.o: Component/src/User.cpp
Component/CMakeFiles/Component.dir/src/User.cpp.o: Component/CMakeFiles/Component.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Component/CMakeFiles/Component.dir/src/User.cpp.o"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Component/CMakeFiles/Component.dir/src/User.cpp.o -MF CMakeFiles/Component.dir/src/User.cpp.o.d -o CMakeFiles/Component.dir/src/User.cpp.o -c /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/User.cpp

Component/CMakeFiles/Component.dir/src/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Component.dir/src/User.cpp.i"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/User.cpp > CMakeFiles/Component.dir/src/User.cpp.i

Component/CMakeFiles/Component.dir/src/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Component.dir/src/User.cpp.s"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/src/User.cpp -o CMakeFiles/Component.dir/src/User.cpp.s

# Object files for target Component
Component_OBJECTS = \
"CMakeFiles/Component.dir/src/Map.cpp.o" \
"CMakeFiles/Component.dir/src/Unit.cpp.o" \
"CMakeFiles/Component.dir/src/User.cpp.o"

# External object files for target Component
Component_EXTERNAL_OBJECTS =

Component/libComponent.a: Component/CMakeFiles/Component.dir/src/Map.cpp.o
Component/libComponent.a: Component/CMakeFiles/Component.dir/src/Unit.cpp.o
Component/libComponent.a: Component/CMakeFiles/Component.dir/src/User.cpp.o
Component/libComponent.a: Component/CMakeFiles/Component.dir/build.make
Component/libComponent.a: Component/CMakeFiles/Component.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libComponent.a"
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && $(CMAKE_COMMAND) -P CMakeFiles/Component.dir/cmake_clean_target.cmake
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Component.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Component/CMakeFiles/Component.dir/build: Component/libComponent.a
.PHONY : Component/CMakeFiles/Component.dir/build

Component/CMakeFiles/Component.dir/clean:
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component && $(CMAKE_COMMAND) -P CMakeFiles/Component.dir/cmake_clean.cmake
.PHONY : Component/CMakeFiles/Component.dir/clean

Component/CMakeFiles/Component.dir/depend:
	cd /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++ && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++ /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++ /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component /Users/igwanho/Desktop/code/Git/DesignPattern/Practice_C++/Practice_C++/Component/CMakeFiles/Component.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : Component/CMakeFiles/Component.dir/depend

