file(GLOB HEADERS "include/eosio/pixel_plugin/*.hpp" )
add_library( pixel_plugin
             pixel_plugin.cpp
             ${HEADERS} )

target_link_libraries( pixel_plugin chain_plugin producer_plugin appbase fc plugin_lib )
target_include_directories( pixel_plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include 
${CMAKE_CURRENT_SOURCE_DIR}/../chain_interface/include  
${CMAKE_CURRENT_SOURCE_DIR}/../../libraries/appbase/include
${CMAKE_CURRENT_SOURCE_DIR}/../plugin_lib/include)
## see dimensionchain.io
