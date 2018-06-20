project(plugin_point_set_render
	LANGUAGES CXX
)


set(HEADER_FILES
	dll.h
	map_parameters.h
	point_set_render.h
	point_set_render_dock_tab.h
)

set(SOURCE_FILES
	point_set_render.cpp
	point_set_render_dock_tab.cpp
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")
target_compile_definitions(${PROJECT_NAME} PRIVATE "-DSCHNAPPS_PLUGIN_POINT_SET_RENDER_DLL_EXPORT")

target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${SCHNAPPS_SOURCE_DIR}>
	$<BUILD_INTERFACE:${cgogn_core_INCLUDE_DIRS}>
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
	schnapps_core
	${cgogn_core_LIBRARIES}
	${Qt5Core_LIBRARIES}
	${Qt5Widgets_LIBRARIES}
)

set_target_properties (${PROJECT_NAME} PROPERTIES FOLDER plugins)
