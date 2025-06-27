# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Ui_for_Hw1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Ui_for_Hw1_autogen.dir\\ParseCache.txt"
  "Ui_for_Hw1_autogen"
  )
endif()
