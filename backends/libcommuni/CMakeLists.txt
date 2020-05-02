cmake_minimum_required(VERSION 2.6)

file(GLOB SRC *.cpp)

if(NOT ENABLE_QT4)
	include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS})
endif()

add_definitions(-DQT_NO_KEYWORDS)
add_executable(spectrum2_libcommuni_backend ${SRC})

set_target_properties(spectrum2_libcommuni_backend PROPERTIES AUTOMOC ON AUTOMOC_MOC_OPTIONS -DBOOST_TT_HAS_OPERATOR_HPP_INCLUDED)

target_link_libraries(spectrum2_libcommuni_backend ${IRC_LIBRARY} transport)
if(ENABLE_QT4)
	target_link_libraries(spectrum2_libcommuni_backend Qt4::QtNetwork Qt4::QtCore)
else()
	target_link_libraries(spectrum2_libcommuni_backend Qt5::Network Qt5::Core)
endif()
if(NOT WIN32)
	target_link_libraries(spectrum2_libcommuni_backend pthread)
endif()

install(TARGETS spectrum2_libcommuni_backend RUNTIME DESTINATION bin)
