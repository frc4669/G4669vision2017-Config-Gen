# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cyanide/Desktop/G4669vision2017-Config-Gen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cyanide/Desktop/G4669vision2017-Config-Gen/build

# Include any dependencies generated for this target.
include CMakeFiles/cv_configGen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cv_configGen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cv_configGen.dir/flags.make

CMakeFiles/cv_configGen.dir/configGen.cpp.o: CMakeFiles/cv_configGen.dir/flags.make
CMakeFiles/cv_configGen.dir/configGen.cpp.o: ../configGen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cyanide/Desktop/G4669vision2017-Config-Gen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cv_configGen.dir/configGen.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cv_configGen.dir/configGen.cpp.o -c /home/cyanide/Desktop/G4669vision2017-Config-Gen/configGen.cpp

CMakeFiles/cv_configGen.dir/configGen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cv_configGen.dir/configGen.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cyanide/Desktop/G4669vision2017-Config-Gen/configGen.cpp > CMakeFiles/cv_configGen.dir/configGen.cpp.i

CMakeFiles/cv_configGen.dir/configGen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cv_configGen.dir/configGen.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cyanide/Desktop/G4669vision2017-Config-Gen/configGen.cpp -o CMakeFiles/cv_configGen.dir/configGen.cpp.s

CMakeFiles/cv_configGen.dir/configGen.cpp.o.requires:

.PHONY : CMakeFiles/cv_configGen.dir/configGen.cpp.o.requires

CMakeFiles/cv_configGen.dir/configGen.cpp.o.provides: CMakeFiles/cv_configGen.dir/configGen.cpp.o.requires
	$(MAKE) -f CMakeFiles/cv_configGen.dir/build.make CMakeFiles/cv_configGen.dir/configGen.cpp.o.provides.build
.PHONY : CMakeFiles/cv_configGen.dir/configGen.cpp.o.provides

CMakeFiles/cv_configGen.dir/configGen.cpp.o.provides.build: CMakeFiles/cv_configGen.dir/configGen.cpp.o


# Object files for target cv_configGen
cv_configGen_OBJECTS = \
"CMakeFiles/cv_configGen.dir/configGen.cpp.o"

# External object files for target cv_configGen
cv_configGen_EXTERNAL_OBJECTS =

cv_configGen: CMakeFiles/cv_configGen.dir/configGen.cpp.o
cv_configGen: CMakeFiles/cv_configGen.dir/build.make
cv_configGen: /usr/local/lib/libopencv_shape.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_stitching.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_superres.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_videostab.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_objdetect.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_calib3d.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_features2d.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_flann.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_highgui.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_ml.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_photo.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_video.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_videoio.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_imgproc.so.3.2.0
cv_configGen: /usr/local/lib/libopencv_core.so.3.2.0
cv_configGen: CMakeFiles/cv_configGen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cyanide/Desktop/G4669vision2017-Config-Gen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cv_configGen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cv_configGen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cv_configGen.dir/build: cv_configGen

.PHONY : CMakeFiles/cv_configGen.dir/build

CMakeFiles/cv_configGen.dir/requires: CMakeFiles/cv_configGen.dir/configGen.cpp.o.requires

.PHONY : CMakeFiles/cv_configGen.dir/requires

CMakeFiles/cv_configGen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cv_configGen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cv_configGen.dir/clean

CMakeFiles/cv_configGen.dir/depend:
	cd /home/cyanide/Desktop/G4669vision2017-Config-Gen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cyanide/Desktop/G4669vision2017-Config-Gen /home/cyanide/Desktop/G4669vision2017-Config-Gen /home/cyanide/Desktop/G4669vision2017-Config-Gen/build /home/cyanide/Desktop/G4669vision2017-Config-Gen/build /home/cyanide/Desktop/G4669vision2017-Config-Gen/build/CMakeFiles/cv_configGen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cv_configGen.dir/depend
