platform(sim COMPLETE HOSTED PARENT common)

if(NOT CMAKE_CROSSCOMPILING)
  return()
endif()

include_directories(BEFORE SYSTEM .)

install(FILES assert.h stdlib.h TYPE INCLUDE)

add_platform_library(sim-crt0)
merge_libraries(sim-crt0
  common-exit-custom
  common-init-stack
)
target_compile_options(sim-crt0 PRIVATE -fno-lto)

add_platform_library(sim-c
  assert.c
  putchar.c
  stdlib.c
  sim-io.c
)
target_include_directories(sim-c SYSTEM BEFORE PUBLIC .)
