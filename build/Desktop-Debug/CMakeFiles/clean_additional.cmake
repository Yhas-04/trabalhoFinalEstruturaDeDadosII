# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/TrabalhoFinal_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/TrabalhoFinal_autogen.dir/ParseCache.txt"
  "TrabalhoFinal_autogen"
  )
endif()
