#pragma once


#ifdef _WIN32
  #define SLOPTMAP_EXPORT __declspec(dllexport)
#else
  #define SLOPTMAP_EXPORT
#endif

SLOPTMAP_EXPORT void SloptMap();
