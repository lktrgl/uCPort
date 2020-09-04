cmake_minimum_required(VERSION 3.5)

project ( uCPort )

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

if(NOT IS_SUBPROJECT)
    set ( CMAKE_C_STANDARD 99 )
    set ( CMAKE_CXX_STANDARD 17 )
    set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
    set ( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3 -o0" )
else()
    set ( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNDEBUG" )
    set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG" )
endif()

#------------------------------------------------------

if(USE_PORT_STM8)

include_directories (
     contrib/STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver/inc
     include/port_stm8/impl
     include
     )

add_subdirectory( contrib/STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver )

set (stm8_src src/port_stm8
    )
set (stm8_include include/port_stm8
    )
set (port_stm8_libsources
     ${stm8_src}/stm8_device.c
     ${stm8_include}/stm8_device.h

     ${stm8_src}/stm8_device_humidity.c
     ${stm8_include}/impl/stm8_device_humidity.h
     ${stm8_src}/stm8_device_temperature.c
     ${stm8_include}/impl/stm8_device_temperature.h
     ${stm8_src}/stm8_device_light.c
     ${stm8_include}/impl/stm8_device_light.h
     ${stm8_src}/stm8_device_time.c
     ${stm8_include}/impl/stm8_device_time.h
     ${stm8_src}/stm8_device_motor.c
     ${stm8_include}/impl/stm8_device_motor.h
     ${stm8_src}/stm8_device_exit.c
     ${stm8_include}/impl/stm8_device_led.h
     ${stm8_src}/stm8_device_led.c
     ${stm8_include}/impl/stm8_device_exit.h
     ${stm8_src}/stm8s_it.c
     ${stm8_include}/impl/stm8s_it.h
     )

add_library ( port_stm8
    ${port_stm8_libsources}
     )
endif()

#------------------------------------------------------

if(USE_PORT_TEST)

include_directories (
     include
     )

set (test_src src/port_test
    )
set (test_include include/port_test
    )
set (port_test_libsources
     ${test_src}/test_device.c
     ${test_include}/test_device.h
     )

add_library ( port_test
    ${port_test_libsources}
     )
endif()
