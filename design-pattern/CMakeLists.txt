# CMakeList.txt : CMake project for design-pattern, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (design-pattern "design-pattern.cpp" "design-pattern.h" "factory.h" "abstract_factory.h" "builder.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET design-pattern PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
