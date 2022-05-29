cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
project(RP2040_ISODAQ)
set(target_name RP2040_ISODAQ)

pico_sdk_init()

add_executable(${target_name})

pico_generate_pio_header(${target_name} ${CMAKE_CURRENT_LIST_DIR}/tx.pio)
pico_generate_pio_header(${target_name} ${CMAKE_CURRENT_LIST_DIR}/rx.pio)

target_sources(${target_name} PRIVATE
    main.c
    hwinit.c
    tbl_8b10b.c
    rx_func.c
    )

target_link_libraries(${target_name} PRIVATE
    pico_stdlib
    pico_multicore
    hardware_pio
    hardware_adc
    hardware_i2c
    )

pico_add_extra_outputs(${target_name})
