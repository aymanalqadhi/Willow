#ifndef WILLOW_MEMORY_H
#define WILLOW_MEMORY_H

#include <stddef.h>

#define W_MALLOC(type, n) ((type *)w_malloc(sizeof(type) * n))

void *w_malloc(size_t n);
void  w_free(void *data);
void *w_memdup(const void *data, size_t len);
char *w_strdup(const char *str);
char *w_strndup(const char *str, size_t len);

#endif /* WILLOW_MEMORY_H */
