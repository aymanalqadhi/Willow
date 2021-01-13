#include "willow/logger.h"

#include <stdarg.h>
#include <stdio.h>

#ifndef USE_COLORS
static const char *log_levels[] = {"TRACE", "DEBUG", "INFO",
                                   "WARN",  "ERROR", "FATAL"};
#else
static const char *log_levels[] = {"TRACE",
                                   ANSI_COLOR_BLUE "DEBUG" ANSI_COLOR_RESET,
                                   ANSI_COLOR_CYAN "INFO" ANSI_COLOR_RESET,
                                   ANSI_COLOR_MAGENTA "WARN" ANSI_COLOR_RESET,
                                   ANSI_COLOR_RED "ERROR" ANSI_COLOR_RESET,
                                   ANSI_COLOR_RED "FATAL" ANSI_COLOR_RESET};
#endif

void w_log_msg(enum brt_log_level level, const char *fmt, ...) {
  va_list arg;

  if (level < LOG_TRACE || level > LOG_FATAL) {
    log_error("Invalid log level was supplied");
    return;
  }

  printf("[%s] ", log_levels[level]);

  va_start(arg, fmt);
  vprintf(fmt, arg);
  va_end(arg);

  putchar('\n');
}
