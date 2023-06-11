#include <cstdio>

#define NORMAL      "\x1B[0m"
#define RED         "\x1B[31m"
#define GREEN       "\x1B[32m"
#define YELLOW      "\x1B[33m"
#define BLUE        "\x1B[34m"
#define MAGENTA     "\x1B[35m"
#define CYAN        "\x1B[36m"
#define WHITE       "\x1B[37m"


#define colored_fprintf(stream, color, fmt, ...) std::fprintf(stream, color fmt, #__VA_ARGS__)

#define LOG_INFO(...) do { \
        colored_fprintf(stdout, GREEN, "[   INFO   ] "); \
        colored_fprintf(stdout, NORMAL, __VA_ARGS__); \
    } while (false)

#define LOG_WARN(...) do { \
        colored_fprintf(stderr, YELLOW, "[   WARN   ] "); \
        colored_fprintf(stderr, YELLOW, __VA_ARGS__); \
    } while (false)

#define LOG_ERROR(...) do { \
        colored_fprintf(stderr, RED, "[  ERROR!  ] "); \
        colored_fprintf(stderr, RED, __VA_ARGS__); \
    } while(0)
