#ifndef WILLOW_LOGGER_H
#define WILLOW_LOGGER_H

#include "willow/error.h"

#if !defined(_WIN32)
#define USE_COLORS         1
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#else
#define USE_COLORS 0
#endif

#define log_trace(fmt, ...) w_log_msg(LOG_TRACE, fmt, ##__VA_ARGS__)
#define log_debug(fmt, ...) w_log_msg(LOG_DEBUG, fmt, ##__VA_ARGS__)
#define log_info(fmt, ...)  w_log_msg(LOG_INFO, fmt, ##__VA_ARGS__)
#define log_warn(fmt, ...)  w_log_msg(LOG_WARN, fmt, ##__VA_ARGS__)
#define log_error(fmt, ...) w_log_msg(LOG_ERROR, fmt, ##__VA_ARGS__)
#define log_fatal(fmt, ...) w_log_msg(LOG_FATAL, fmt, ##__VA_ARGS__)

#define w_perror(msg, err) log_error("%s: %s", msg, w_strerror(err))
#define w_pfatal(msg, err) log_fatal("%s: %s", msg, w_strerror(err))

enum brt_log_level
{
  LOG_TRACE = 0,
  LOG_DEBUG = 1,
  LOG_INFO  = 2,
  LOG_WARN  = 3,
  LOG_ERROR = 4,
  LOG_FATAL = 5
};

void w_log_msg(enum brt_log_level level, const char *fmt, ...);

#endif /* WILLOW_LOGGER_H */
