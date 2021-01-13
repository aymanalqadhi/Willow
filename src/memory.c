#include "willow/memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *w_malloc(size_t n) {
  void *ret;

  if (!(ret = malloc(n))) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  return ret;
}

void w_free(void *data) { free(data); }

void *w_memdup(const void *data, size_t sz) {
  void *ret = w_malloc(sz);
  memcpy(ret, data, sz);
  return ret;
}

char *w_strdup(const char *str) {
  char *ret = W_MALLOC(char, strlen(str) + 1);
  strcpy(ret, str);
  return ret;
}

char *w_strndup(const char *str, size_t len) {
  len = strnlen(str, len);
  return (char *)w_memdup((const void *)str, len);
}
