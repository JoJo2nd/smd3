

#if SMD_PLATFORM_WINDOWS
#  define SMD_PLATFORM_DEFINED (1)
#elif SMD_PLATFORM_MACOS
#  define SMD_PLATFORM_DEFINED (1)
#endif
//#define SMD_PLATFORM_LINUX

#if !SMD_PLATFORM_DEFINED
#  error Platform not defined
#endif

#if defined (SMD_PLATFORM_MACOS)
#  define SMD_PLATFORM_USE_POSIX (1)
#endif

#if SMD_PLATFORM_WINDOWS
#  define SMD_API
//#  if defined(libsmd_EXPORTS)
//#    define SMD_API __declspec(dllexport)
//#  else
//#    define SMD_API __declspec(dllimport)
//#  endif
#else // non windows
#  define SMD_API
#endif

