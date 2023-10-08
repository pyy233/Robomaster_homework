# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/sjtu-rm/Workspace/homework2/simulate_shooting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sjtu-rm/Workspace/homework2/simulate_shooting/build

# Include any dependencies generated for this target.
include CMakeFiles/ocv.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ocv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ocv.dir/flags.make

CMakeFiles/ocv.dir/main.cpp.o: CMakeFiles/ocv.dir/flags.make
CMakeFiles/ocv.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sjtu-rm/Workspace/homework2/simulate_shooting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ocv.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ocv.dir/main.cpp.o -c /home/sjtu-rm/Workspace/homework2/simulate_shooting/main.cpp

CMakeFiles/ocv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ocv.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sjtu-rm/Workspace/homework2/simulate_shooting/main.cpp > CMakeFiles/ocv.dir/main.cpp.i

CMakeFiles/ocv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ocv.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sjtu-rm/Workspace/homework2/simulate_shooting/main.cpp -o CMakeFiles/ocv.dir/main.cpp.s

# Object files for target ocv
ocv_OBJECTS = \
"CMakeFiles/ocv.dir/main.cpp.o"

# External object files for target ocv
ocv_EXTERNAL_OBJECTS =

ocv: CMakeFiles/ocv.dir/main.cpp.o
ocv: CMakeFiles/ocv.dir/build.make
ocv: /usr/local/lib/libopencv_stitching.so.4.4.0
ocv: /usr/local/lib/libopencv_alphamat.so.4.4.0
ocv: /usr/local/lib/libopencv_aruco.so.4.4.0
ocv: /usr/local/lib/libopencv_bgsegm.so.4.4.0
ocv: /usr/local/lib/libopencv_bioinspired.so.4.4.0
ocv: /usr/local/lib/libopencv_ccalib.so.4.4.0
ocv: /usr/local/lib/libopencv_dnn_objdetect.so.4.4.0
ocv: /usr/local/lib/libopencv_dnn_superres.so.4.4.0
ocv: /usr/local/lib/libopencv_dpm.so.4.4.0
ocv: /usr/local/lib/libopencv_face.so.4.4.0
ocv: /usr/local/lib/libopencv_freetype.so.4.4.0
ocv: /usr/local/lib/libopencv_fuzzy.so.4.4.0
ocv: /usr/local/lib/libopencv_hfs.so.4.4.0
ocv: /usr/local/lib/libopencv_img_hash.so.4.4.0
ocv: /usr/local/lib/libopencv_intensity_transform.so.4.4.0
ocv: /usr/local/lib/libopencv_line_descriptor.so.4.4.0
ocv: /usr/local/lib/libopencv_quality.so.4.4.0
ocv: /usr/local/lib/libopencv_rapid.so.4.4.0
ocv: /usr/local/lib/libopencv_reg.so.4.4.0
ocv: /usr/local/lib/libopencv_rgbd.so.4.4.0
ocv: /usr/local/lib/libopencv_saliency.so.4.4.0
ocv: /usr/local/lib/libopencv_sfm.so.4.4.0
ocv: /usr/local/lib/libopencv_stereo.so.4.4.0
ocv: /usr/local/lib/libopencv_structured_light.so.4.4.0
ocv: /usr/local/lib/libopencv_superres.so.4.4.0
ocv: /usr/local/lib/libopencv_surface_matching.so.4.4.0
ocv: /usr/local/lib/libopencv_tracking.so.4.4.0
ocv: /usr/local/lib/libopencv_videostab.so.4.4.0
ocv: /usr/local/lib/libopencv_xfeatures2d.so.4.4.0
ocv: /usr/local/lib/libopencv_xobjdetect.so.4.4.0
ocv: /usr/local/lib/libopencv_xphoto.so.4.4.0
ocv: /usr/local/lib/libopencv_highgui.so.4.4.0
ocv: /usr/local/lib/libopencv_shape.so.4.4.0
ocv: /usr/local/lib/libopencv_datasets.so.4.4.0
ocv: /usr/local/lib/libopencv_plot.so.4.4.0
ocv: /usr/local/lib/libopencv_text.so.4.4.0
ocv: /usr/local/lib/libopencv_dnn.so.4.4.0
ocv: /usr/local/lib/libopencv_ml.so.4.4.0
ocv: /usr/local/lib/libopencv_phase_unwrapping.so.4.4.0
ocv: /usr/local/lib/libopencv_optflow.so.4.4.0
ocv: /usr/local/lib/libopencv_ximgproc.so.4.4.0
ocv: /usr/local/lib/libopencv_video.so.4.4.0
ocv: /usr/local/lib/libopencv_videoio.so.4.4.0
ocv: /usr/local/lib/libopencv_imgcodecs.so.4.4.0
ocv: /usr/local/lib/libopencv_objdetect.so.4.4.0
ocv: /usr/local/lib/libopencv_calib3d.so.4.4.0
ocv: /usr/local/lib/libopencv_features2d.so.4.4.0
ocv: /usr/local/lib/libopencv_flann.so.4.4.0
ocv: /usr/local/lib/libopencv_photo.so.4.4.0
ocv: /usr/local/lib/libopencv_imgproc.so.4.4.0
ocv: /usr/local/lib/libopencv_core.so.4.4.0
ocv: CMakeFiles/ocv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sjtu-rm/Workspace/homework2/simulate_shooting/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ocv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ocv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ocv.dir/build: ocv

.PHONY : CMakeFiles/ocv.dir/build

CMakeFiles/ocv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ocv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ocv.dir/clean

CMakeFiles/ocv.dir/depend:
	cd /home/sjtu-rm/Workspace/homework2/simulate_shooting/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sjtu-rm/Workspace/homework2/simulate_shooting /home/sjtu-rm/Workspace/homework2/simulate_shooting /home/sjtu-rm/Workspace/homework2/simulate_shooting/build /home/sjtu-rm/Workspace/homework2/simulate_shooting/build /home/sjtu-rm/Workspace/homework2/simulate_shooting/build/CMakeFiles/ocv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ocv.dir/depend

