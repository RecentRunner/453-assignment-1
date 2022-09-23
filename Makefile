# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/user/453-skeleton-updated

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/user/453-skeleton-updated

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/user/453-skeleton-updated/CMakeFiles /home/user/453-skeleton-updated//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/user/453-skeleton-updated/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named 453-skeleton

# Build rule for target.
453-skeleton: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 453-skeleton
.PHONY : 453-skeleton

# fast build rule for target.
453-skeleton/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/build
.PHONY : 453-skeleton/fast

#=============================================================================
# Target rules for targets named glad

# Build rule for target.
glad: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 glad
.PHONY : glad

# fast build rule for target.
glad/fast:
	$(MAKE) $(MAKESILENT) -f thirdparty/glad/CMakeFiles/glad.dir/build.make thirdparty/glad/CMakeFiles/glad.dir/build
.PHONY : glad/fast

#=============================================================================
# Target rules for targets named uninstall

# Build rule for target.
uninstall: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 uninstall
.PHONY : uninstall

# fast build rule for target.
uninstall/fast:
	$(MAKE) $(MAKESILENT) -f thirdparty/glfw-3.3.2/CMakeFiles/uninstall.dir/build.make thirdparty/glfw-3.3.2/CMakeFiles/uninstall.dir/build
.PHONY : uninstall/fast

#=============================================================================
# Target rules for targets named glfw

# Build rule for target.
glfw: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 glfw
.PHONY : glfw

# fast build rule for target.
glfw/fast:
	$(MAKE) $(MAKESILENT) -f thirdparty/glfw-3.3.2/src/CMakeFiles/glfw.dir/build.make thirdparty/glfw-3.3.2/src/CMakeFiles/glfw.dir/build
.PHONY : glfw/fast

#=============================================================================
# Target rules for targets named fmt

# Build rule for target.
fmt: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 fmt
.PHONY : fmt

# fast build rule for target.
fmt/fast:
	$(MAKE) $(MAKESILENT) -f thirdparty/fmt-7.0.3/CMakeFiles/fmt.dir/build.make thirdparty/fmt-7.0.3/CMakeFiles/fmt.dir/build
.PHONY : fmt/fast

453-skeleton/GLDebug.o: 453-skeleton/GLDebug.cpp.o
.PHONY : 453-skeleton/GLDebug.o

# target to build an object file
453-skeleton/GLDebug.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/GLDebug.cpp.o
.PHONY : 453-skeleton/GLDebug.cpp.o

453-skeleton/GLDebug.i: 453-skeleton/GLDebug.cpp.i
.PHONY : 453-skeleton/GLDebug.i

# target to preprocess a source file
453-skeleton/GLDebug.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/GLDebug.cpp.i
.PHONY : 453-skeleton/GLDebug.cpp.i

453-skeleton/GLDebug.s: 453-skeleton/GLDebug.cpp.s
.PHONY : 453-skeleton/GLDebug.s

# target to generate assembly for a file
453-skeleton/GLDebug.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/GLDebug.cpp.s
.PHONY : 453-skeleton/GLDebug.cpp.s

453-skeleton/GLHandles.o: 453-skeleton/GLHandles.cpp.o
.PHONY : 453-skeleton/GLHandles.o

# target to build an object file
453-skeleton/GLHandles.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/GLHandles.cpp.o
.PHONY : 453-skeleton/GLHandles.cpp.o

453-skeleton/GLHandles.i: 453-skeleton/GLHandles.cpp.i
.PHONY : 453-skeleton/GLHandles.i

# target to preprocess a source file
453-skeleton/GLHandles.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/GLHandles.cpp.i
.PHONY : 453-skeleton/GLHandles.cpp.i

453-skeleton/GLHandles.s: 453-skeleton/GLHandles.cpp.s
.PHONY : 453-skeleton/GLHandles.s

# target to generate assembly for a file
453-skeleton/GLHandles.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/GLHandles.cpp.s
.PHONY : 453-skeleton/GLHandles.cpp.s

453-skeleton/Geometry.o: 453-skeleton/Geometry.cpp.o
.PHONY : 453-skeleton/Geometry.o

# target to build an object file
453-skeleton/Geometry.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Geometry.cpp.o
.PHONY : 453-skeleton/Geometry.cpp.o

453-skeleton/Geometry.i: 453-skeleton/Geometry.cpp.i
.PHONY : 453-skeleton/Geometry.i

# target to preprocess a source file
453-skeleton/Geometry.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Geometry.cpp.i
.PHONY : 453-skeleton/Geometry.cpp.i

453-skeleton/Geometry.s: 453-skeleton/Geometry.cpp.s
.PHONY : 453-skeleton/Geometry.s

# target to generate assembly for a file
453-skeleton/Geometry.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Geometry.cpp.s
.PHONY : 453-skeleton/Geometry.cpp.s

453-skeleton/Shader.o: 453-skeleton/Shader.cpp.o
.PHONY : 453-skeleton/Shader.o

# target to build an object file
453-skeleton/Shader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Shader.cpp.o
.PHONY : 453-skeleton/Shader.cpp.o

453-skeleton/Shader.i: 453-skeleton/Shader.cpp.i
.PHONY : 453-skeleton/Shader.i

# target to preprocess a source file
453-skeleton/Shader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Shader.cpp.i
.PHONY : 453-skeleton/Shader.cpp.i

453-skeleton/Shader.s: 453-skeleton/Shader.cpp.s
.PHONY : 453-skeleton/Shader.s

# target to generate assembly for a file
453-skeleton/Shader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Shader.cpp.s
.PHONY : 453-skeleton/Shader.cpp.s

453-skeleton/ShaderProgram.o: 453-skeleton/ShaderProgram.cpp.o
.PHONY : 453-skeleton/ShaderProgram.o

# target to build an object file
453-skeleton/ShaderProgram.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/ShaderProgram.cpp.o
.PHONY : 453-skeleton/ShaderProgram.cpp.o

453-skeleton/ShaderProgram.i: 453-skeleton/ShaderProgram.cpp.i
.PHONY : 453-skeleton/ShaderProgram.i

# target to preprocess a source file
453-skeleton/ShaderProgram.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/ShaderProgram.cpp.i
.PHONY : 453-skeleton/ShaderProgram.cpp.i

453-skeleton/ShaderProgram.s: 453-skeleton/ShaderProgram.cpp.s
.PHONY : 453-skeleton/ShaderProgram.s

# target to generate assembly for a file
453-skeleton/ShaderProgram.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/ShaderProgram.cpp.s
.PHONY : 453-skeleton/ShaderProgram.cpp.s

453-skeleton/VertexArray.o: 453-skeleton/VertexArray.cpp.o
.PHONY : 453-skeleton/VertexArray.o

# target to build an object file
453-skeleton/VertexArray.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/VertexArray.cpp.o
.PHONY : 453-skeleton/VertexArray.cpp.o

453-skeleton/VertexArray.i: 453-skeleton/VertexArray.cpp.i
.PHONY : 453-skeleton/VertexArray.i

# target to preprocess a source file
453-skeleton/VertexArray.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/VertexArray.cpp.i
.PHONY : 453-skeleton/VertexArray.cpp.i

453-skeleton/VertexArray.s: 453-skeleton/VertexArray.cpp.s
.PHONY : 453-skeleton/VertexArray.s

# target to generate assembly for a file
453-skeleton/VertexArray.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/VertexArray.cpp.s
.PHONY : 453-skeleton/VertexArray.cpp.s

453-skeleton/VertexBuffer.o: 453-skeleton/VertexBuffer.cpp.o
.PHONY : 453-skeleton/VertexBuffer.o

# target to build an object file
453-skeleton/VertexBuffer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/VertexBuffer.cpp.o
.PHONY : 453-skeleton/VertexBuffer.cpp.o

453-skeleton/VertexBuffer.i: 453-skeleton/VertexBuffer.cpp.i
.PHONY : 453-skeleton/VertexBuffer.i

# target to preprocess a source file
453-skeleton/VertexBuffer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/VertexBuffer.cpp.i
.PHONY : 453-skeleton/VertexBuffer.cpp.i

453-skeleton/VertexBuffer.s: 453-skeleton/VertexBuffer.cpp.s
.PHONY : 453-skeleton/VertexBuffer.s

# target to generate assembly for a file
453-skeleton/VertexBuffer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/VertexBuffer.cpp.s
.PHONY : 453-skeleton/VertexBuffer.cpp.s

453-skeleton/Window.o: 453-skeleton/Window.cpp.o
.PHONY : 453-skeleton/Window.o

# target to build an object file
453-skeleton/Window.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Window.cpp.o
.PHONY : 453-skeleton/Window.cpp.o

453-skeleton/Window.i: 453-skeleton/Window.cpp.i
.PHONY : 453-skeleton/Window.i

# target to preprocess a source file
453-skeleton/Window.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Window.cpp.i
.PHONY : 453-skeleton/Window.cpp.i

453-skeleton/Window.s: 453-skeleton/Window.cpp.s
.PHONY : 453-skeleton/Window.s

# target to generate assembly for a file
453-skeleton/Window.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/Window.cpp.s
.PHONY : 453-skeleton/Window.cpp.s

453-skeleton/main.o: 453-skeleton/main.cpp.o
.PHONY : 453-skeleton/main.o

# target to build an object file
453-skeleton/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/main.cpp.o
.PHONY : 453-skeleton/main.cpp.o

453-skeleton/main.i: 453-skeleton/main.cpp.i
.PHONY : 453-skeleton/main.i

# target to preprocess a source file
453-skeleton/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/main.cpp.i
.PHONY : 453-skeleton/main.cpp.i

453-skeleton/main.s: 453-skeleton/main.cpp.s
.PHONY : 453-skeleton/main.s

# target to generate assembly for a file
453-skeleton/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/453-skeleton.dir/build.make CMakeFiles/453-skeleton.dir/453-skeleton/main.cpp.s
.PHONY : 453-skeleton/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... uninstall"
	@echo "... 453-skeleton"
	@echo "... fmt"
	@echo "... glad"
	@echo "... glfw"
	@echo "... 453-skeleton/GLDebug.o"
	@echo "... 453-skeleton/GLDebug.i"
	@echo "... 453-skeleton/GLDebug.s"
	@echo "... 453-skeleton/GLHandles.o"
	@echo "... 453-skeleton/GLHandles.i"
	@echo "... 453-skeleton/GLHandles.s"
	@echo "... 453-skeleton/Geometry.o"
	@echo "... 453-skeleton/Geometry.i"
	@echo "... 453-skeleton/Geometry.s"
	@echo "... 453-skeleton/Shader.o"
	@echo "... 453-skeleton/Shader.i"
	@echo "... 453-skeleton/Shader.s"
	@echo "... 453-skeleton/ShaderProgram.o"
	@echo "... 453-skeleton/ShaderProgram.i"
	@echo "... 453-skeleton/ShaderProgram.s"
	@echo "... 453-skeleton/VertexArray.o"
	@echo "... 453-skeleton/VertexArray.i"
	@echo "... 453-skeleton/VertexArray.s"
	@echo "... 453-skeleton/VertexBuffer.o"
	@echo "... 453-skeleton/VertexBuffer.i"
	@echo "... 453-skeleton/VertexBuffer.s"
	@echo "... 453-skeleton/Window.o"
	@echo "... 453-skeleton/Window.i"
	@echo "... 453-skeleton/Window.s"
	@echo "... 453-skeleton/main.o"
	@echo "... 453-skeleton/main.i"
	@echo "... 453-skeleton/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
