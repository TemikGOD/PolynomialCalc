# CMakeList.txt : CMake project for Polynomial, include source and define
# project specific logic here.
#
file(GLOB UI_SOURCES "UI/myUI/Source/*.cpp")
file(GLOB UI_HEADERS "UI/myUI/Headers/*.h")
file(GLOB TABLE_HEADERS "Tables/*.hpp")

# Add source to this project's executable.
add_executable (PolyMath "PolyApp.cpp" "PolyApp.h" 
						 "Polynomial/Polynomial.h" "Polynomial/Monom.h"
						 "Containers/Vector.h" "Containers/List.h" 
						 "UI/fb/wxUIPM.h" "UI/fb/wxUIPM.cpp" 
						 ${UI_HEADERS} ${UI_SOURCES} ${TABLE_HEADERS})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET PolyMath PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.

add_subdirectory(googletest)

set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})
target_link_libraries("PolyMath" ${wxWidgets_LIBRARIES})