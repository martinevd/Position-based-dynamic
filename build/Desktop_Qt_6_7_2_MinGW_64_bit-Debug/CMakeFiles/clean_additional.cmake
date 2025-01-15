# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Position-based-dynamic_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Position-based-dynamic_autogen.dir\\ParseCache.txt"
  "Position-based-dynamic_autogen"
  )
endif()
