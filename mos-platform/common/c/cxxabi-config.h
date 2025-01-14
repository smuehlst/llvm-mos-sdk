//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef ____CXXABI_CONFIG_H
#define ____CXXABI_CONFIG_H

#if !defined(__has_attribute)
#define __has_attribute(_attribute_) 0
#endif

#if defined(__clang__)
#  define _LIBCXXABI_COMPILER_CLANG
#  ifndef __apple_build_version__
#    define _LIBCXXABI_CLANG_VER (__clang_major__ * 100 + __clang_minor__)
#  endif
#endif


#if !defined(_LIBCXXABI_DISABLE_VISIBILITY_ANNOTATIONS)
#define _LIBCXXABI_HIDDEN __attribute__((__visibility__("hidden")))
#define _LIBCXXABI_DATA_VIS __attribute__((__visibility__("default")))
#define _LIBCXXABI_FUNC_VIS __attribute__((__visibility__("default")))
#if __has_attribute(__type_visibility__)
#define _LIBCXXABI_TYPE_VIS __attribute__((__type_visibility__("default")))
#else
#define _LIBCXXABI_TYPE_VIS __attribute__((__visibility__("default")))
#endif
#else
#define _LIBCXXABI_HIDDEN
#define _LIBCXXABI_DATA_VIS
#define _LIBCXXABI_FUNC_VIS
#define _LIBCXXABI_TYPE_VIS
#endif

#define _LIBCXXABI_WEAK __attribute__((__weak__))

#if defined(__clang__)
#define _LIBCXXABI_COMPILER_CLANG
#endif

#if __has_attribute(__no_sanitize__) && defined(_LIBCXXABI_COMPILER_CLANG)
#define _LIBCXXABI_NO_CFI __attribute__((__no_sanitize__("cfi")))
#else
#define _LIBCXXABI_NO_CFI
#endif


#if defined(_LIBCXXABI_COMPILER_CLANG)
#  if !__has_feature(cxx_exceptions)
#    define _LIBCXXABI_NO_EXCEPTIONS
#  endif
#endif

#endif // ____CXXABI_CONFIG_H
