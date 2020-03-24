#pragma once

#if defined(PAT_LIBRARY)
#  define PAT_EXPORT __declspec(dllexport)
#  define PAT_EXTERN
#else
#  define PAT_EXPORT __declspec(dllimport)
#  define PAT_EXTERN extern
#endif