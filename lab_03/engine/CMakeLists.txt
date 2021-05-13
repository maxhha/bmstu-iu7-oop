cmake_minimum_required(VERSION 3.0)

# Default to release build if not specified
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

project(render LANGUAGES CXX)

if (EMSCRIPTEN)
	set(CMAKE_EXECUTABLE_SUFFIX ".js")

	set(CMAKE_EXE_LINKER_FLAGS "\
		-s WASM=1
		-s MODULARIZE=1 \
    	-s EXPORT_NAME=createEngineModule \
   	 	-s ENVIRONMENT=web \
    	--bind \
		-Oz")

	IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
    	message("debug mode")

		set(CMAKE_EXE_LINKER_FLAGS "\
			-s WASM=1
			-s MODULARIZE=1 \
			-s EXPORT_NAME=createEngineModule \
			-s ENVIRONMENT=web \
			--bind \
			-O0")

	ENDIF(CMAKE_BUILD_TYPE STREQUAL "Debug")

		# -s DISABLE_EXCEPTION_CATCHING=0 \
		# -lGL \
		
		# -s WASM=1 \
		# --closure 1 \
		# -s TEXTDECODER=2 \
		# -s MINIMAL_RUNTIME=2 \
		# -s MIN_WEBGL_VERSION=2 \
		# -s MAX_WEBGL_VERSION=2 \
		# -s GL_SUPPORT_AUTOMATIC_ENABLE_EXTENSIONS=0 \
		# -s GL_EXTENSIONS_IN_PREFIXED_FORMAT=0 \
		# -s GL_POOL_TEMP_BUFFERS=0 \
		# -s AGGRESSIVE_VARIABLE_ELIMINATION=1 \
		# --emit-symbol-map \
		# -s DISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1 \
		# -s FILESYSTEM=0 \
		# -s SUPPORT_ERRNO=0 \
		# -s GL_TRACK_ERRORS=0 \
endif()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*")
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE inc)
