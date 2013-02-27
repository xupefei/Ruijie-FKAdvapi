#ifdef FKADVAPI_EXPORTS
#define FKADVAPI_API extern "C" __declspec(dllexport)
#else
#define FKADVAPI_API __declspec(dllimport)
#endif
