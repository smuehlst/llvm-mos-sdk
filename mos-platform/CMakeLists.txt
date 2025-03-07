include(platform)

if (CMAKE_CROSSCOMPILING)
  add_compile_options(-flto)
else()
  # Make nested build directory cross-compiling to MOS, but using this
  # CMakeLists.txt.
  ExternalProject_Add(mos-platform
    SOURCE_DIR   ${CMAKE_SOURCE_DIR}
    BINARY_DIR   build
    INSTALL_DIR  build/install
    STAMP_DIR    build/stamp
    TMP_DIR      build/tmp
    DOWNLOAD_DIR build
    CMAKE_ARGS
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
      -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
      -DCMAKE_TOOLCHAIN_FILE=${CMAKE_SOURCE_DIR}/cmake/llvm-mos-toolchain.cmake
      -DCMAKE_C_COMPILER=${LLVM_MOS_C_COMPILER}
      -DCMAKE_CXX_COMPILER=${LLVM_MOS_CXX_COMPILER}
      -DCMAKE_ASM_COMPILER=${LLVM_MOS_ASM_COMPILER}
      -DCMAKE_C_FLAGS=${LLVM_MOS_ARCH_FLAGS}
      -DCMAKE_CXX_FLAGS=${LLVM_MOS_ARCH_FLAGS}
      -DCMAKE_ASM_FLAGS=${LLVM_MOS_ARCH_FLAGS}
    USES_TERMINAL_CONFIGURE On
    USES_TERMINAL_BUILD On
    USES_TERMINAL_INSTALL On
    BUILD_ALWAYS On)
  ExternalProject_Get_Property(mos-platform INSTALL_DIR)
  install(DIRECTORY ${INSTALL_DIR}/ DESTINATION .)

  # Clean the build directories with the host project.
  set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY
    ADDITIONAL_CLEAN_FILES build ../examples)
endif()

add_subdirectory(common)
add_subdirectory(atari8)
add_subdirectory(c64)
add_subdirectory(sim)
add_subdirectory(nes)
add_subdirectory(nes-nrom)
add_subdirectory(nes-nrom-128)
add_subdirectory(nes-nrom-256)
add_subdirectory(nes-slrom)
add_subdirectory(osi-c1p)