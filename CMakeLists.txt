cmake_minimum_required(VERSION 3.26)

project(cz_stl)

set(CMAKE_C_STANDARD 23)

##### SANDBOX BEGIN #####
add_executable(
	Sandbox
	sandbox/main.c
  )

target_include_directories(
	Sandbox
	PUBLIC cz_stl
)
###### SANDBOX END ######