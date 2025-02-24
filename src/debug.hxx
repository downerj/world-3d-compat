#ifndef DEBUG_HXX
#define DEBUG_HXX

#ifdef DEBUG
#include <iostream>
#define LOG(x) do { std::cout << x; } while (false);
#define LOG_ERROR(x) do { std::cerr << x; } while (false);
#else
#define LOG(x)
#define LOG_ERROR(x)
#endif // DEBUG

#endif // DEBUG_HXX
