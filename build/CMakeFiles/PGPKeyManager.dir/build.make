# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/Warwick/year2/PLCS/PGPKeyManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/Warwick/year2/PLCS/PGPKeyManager/build

# Include any dependencies generated for this target.
include CMakeFiles/PGPKeyManager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PGPKeyManager.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PGPKeyManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PGPKeyManager.dir/flags.make

CMakeFiles/PGPKeyManager.dir/src/App.cpp.o: CMakeFiles/PGPKeyManager.dir/flags.make
CMakeFiles/PGPKeyManager.dir/src/App.cpp.o: ../src/App.cpp
CMakeFiles/PGPKeyManager.dir/src/App.cpp.o: CMakeFiles/PGPKeyManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/Warwick/year2/PLCS/PGPKeyManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PGPKeyManager.dir/src/App.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGPKeyManager.dir/src/App.cpp.o -MF CMakeFiles/PGPKeyManager.dir/src/App.cpp.o.d -o CMakeFiles/PGPKeyManager.dir/src/App.cpp.o -c /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/App.cpp

CMakeFiles/PGPKeyManager.dir/src/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGPKeyManager.dir/src/App.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/App.cpp > CMakeFiles/PGPKeyManager.dir/src/App.cpp.i

CMakeFiles/PGPKeyManager.dir/src/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGPKeyManager.dir/src/App.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/App.cpp -o CMakeFiles/PGPKeyManager.dir/src/App.cpp.s

CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o: CMakeFiles/PGPKeyManager.dir/flags.make
CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o: ../src/GpgmeRepo.cpp
CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o: CMakeFiles/PGPKeyManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/Warwick/year2/PLCS/PGPKeyManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o -MF CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o.d -o CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o -c /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/GpgmeRepo.cpp

CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/GpgmeRepo.cpp > CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.i

CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/GpgmeRepo.cpp -o CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.s

CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o: CMakeFiles/PGPKeyManager.dir/flags.make
CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o: ../src/KeyList.cpp
CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o: CMakeFiles/PGPKeyManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/Warwick/year2/PLCS/PGPKeyManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o -MF CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o.d -o CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o -c /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/KeyList.cpp

CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/KeyList.cpp > CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.i

CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/KeyList.cpp -o CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.s

CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o: CMakeFiles/PGPKeyManager.dir/flags.make
CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o: ../src/Main.cpp
CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o: CMakeFiles/PGPKeyManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/Warwick/year2/PLCS/PGPKeyManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o -MF CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o.d -o CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o -c /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/Main.cpp

CMakeFiles/PGPKeyManager.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGPKeyManager.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/Main.cpp > CMakeFiles/PGPKeyManager.dir/src/Main.cpp.i

CMakeFiles/PGPKeyManager.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGPKeyManager.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/Main.cpp -o CMakeFiles/PGPKeyManager.dir/src/Main.cpp.s

CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o: CMakeFiles/PGPKeyManager.dir/flags.make
CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o: ../src/NewKeyForm.cpp
CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o: CMakeFiles/PGPKeyManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/Warwick/year2/PLCS/PGPKeyManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o -MF CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o.d -o CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o -c /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/NewKeyForm.cpp

CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/NewKeyForm.cpp > CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.i

CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/Warwick/year2/PLCS/PGPKeyManager/src/NewKeyForm.cpp -o CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.s

# Object files for target PGPKeyManager
PGPKeyManager_OBJECTS = \
"CMakeFiles/PGPKeyManager.dir/src/App.cpp.o" \
"CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o" \
"CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o" \
"CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o" \
"CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o"

# External object files for target PGPKeyManager
PGPKeyManager_EXTERNAL_OBJECTS =

PGPKeyManager: CMakeFiles/PGPKeyManager.dir/src/App.cpp.o
PGPKeyManager: CMakeFiles/PGPKeyManager.dir/src/GpgmeRepo.cpp.o
PGPKeyManager: CMakeFiles/PGPKeyManager.dir/src/KeyList.cpp.o
PGPKeyManager: CMakeFiles/PGPKeyManager.dir/src/Main.cpp.o
PGPKeyManager: CMakeFiles/PGPKeyManager.dir/src/NewKeyForm.cpp.o
PGPKeyManager: CMakeFiles/PGPKeyManager.dir/build.make
PGPKeyManager: CMakeFiles/PGPKeyManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/Warwick/year2/PLCS/PGPKeyManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable PGPKeyManager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PGPKeyManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PGPKeyManager.dir/build: PGPKeyManager
.PHONY : CMakeFiles/PGPKeyManager.dir/build

CMakeFiles/PGPKeyManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PGPKeyManager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PGPKeyManager.dir/clean

CMakeFiles/PGPKeyManager.dir/depend:
	cd /home/parallels/Warwick/year2/PLCS/PGPKeyManager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/Warwick/year2/PLCS/PGPKeyManager /home/parallels/Warwick/year2/PLCS/PGPKeyManager /home/parallels/Warwick/year2/PLCS/PGPKeyManager/build /home/parallels/Warwick/year2/PLCS/PGPKeyManager/build /home/parallels/Warwick/year2/PLCS/PGPKeyManager/build/CMakeFiles/PGPKeyManager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PGPKeyManager.dir/depend

