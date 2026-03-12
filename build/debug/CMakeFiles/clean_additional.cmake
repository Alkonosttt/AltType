# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AltType_autogen"
  "CMakeFiles/AltType_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/AltType_autogen.dir/ParseCache.txt"
  )
endif()
