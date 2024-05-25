cmake_minimum_required(VERSION 3.26)

project(Base)

set(CMAKE_C_STANDARD 23)

##### SANDBOX BEGIN #####
add_executable(
	Sandbox
	sandbox/main.c
  )

target_include_directories(
	Sandbox
	PUBLIC base
)
###### SANDBOX END ######