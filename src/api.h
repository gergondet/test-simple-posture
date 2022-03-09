#pragma once

#if defined _WIN32 || defined __CYGWIN__
#  define PostureTest_DLLIMPORT __declspec(dllimport)
#  define PostureTest_DLLEXPORT __declspec(dllexport)
#  define PostureTest_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#  if __GNUC__ >= 4
#    define PostureTest_DLLIMPORT __attribute__((visibility("default")))
#    define PostureTest_DLLEXPORT __attribute__((visibility("default")))
#    define PostureTest_DLLLOCAL __attribute__((visibility("hidden")))
#  else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#    define PostureTest_DLLIMPORT
#    define PostureTest_DLLEXPORT
#    define PostureTest_DLLLOCAL
#  endif // __GNUC__ >= 4
#endif // defined _WIN32 || defined __CYGWIN__

#ifdef PostureTest_STATIC
// If one is using the library statically, get rid of
// extra information.
#  define PostureTest_DLLAPI
#  define PostureTest_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#  ifdef PostureTest_EXPORTS
#    define PostureTest_DLLAPI PostureTest_DLLEXPORT
#  else
#    define PostureTest_DLLAPI PostureTest_DLLIMPORT
#  endif // PostureTest_EXPORTS
#  define PostureTest_LOCAL PostureTest_DLLLOCAL
#endif // PostureTest_STATIC