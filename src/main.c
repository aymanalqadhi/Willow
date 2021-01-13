#include "willow/lexer.h"
#include "willow/logger.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  struct w_lexer lex;
  FILE *         fp;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s file.w\n", argv[0]);
    return 0;
  }

  if (!(fp = fopen(argv[1], "r"))) {
    w_perror("fopen", errno);
    return EXIT_FAILURE;
  }

  w_lexer_init(&lex);

  if (w_lexer_scan(&lex, fp) != 0) {
    log_fatal("Could not scan source");
    fclose(fp);
    return EXIT_FAILURE;
  }

  for (struct w_token *tok = lex.tokens_head; tok; tok = tok->next) {
    w_token_print(tok);
  }

  fclose(fp);

  return 0;
}
