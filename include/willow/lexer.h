#ifndef WILLOW_LEXER_H
#define WILLOW_LEXER_H

#include "willow/lexer/token.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

struct w_lexer {
  struct w_token *tokens_head, *tokens_tail;

  size_t tokens_count;
  size_t lines_count;
  bool   is_valid;
};

int w_lexer_init(struct w_lexer *lexer);
int w_lexer_get_next_token(struct w_lexer *lexer, FILE *fp);
int w_lexer_scan(struct w_lexer *lexer, FILE *fp);

#endif /* WILLOW_LEXER_H */
