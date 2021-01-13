#include "willow/lexer.h"
#include "willow/logger.h"
#include "willow/memory.h"

#include <assert.h>
#include <errno.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAKE_PATTERN(var, patt, flags)                                         \
  regex_t var;                                                                 \
  regcomp(&var, patt, flags);

static char *read_to_end(FILE *fp, size_t *sz) {
  long  len, pos;
  char *ret;

  if ((pos = ftell(fp)) < 0) {
    w_perror("ftell", pos);
  } else if (fseek(fp, 0, SEEK_END) != 0) {
    w_perror("fseek", errno);
  } else if ((len = ftell(fp)) < 0) {
    w_perror("ftell", pos);
  } else if (fseek(fp, pos, SEEK_SET) != 0) {
    w_perror("fseek", errno);
  } else {
    ret = W_MALLOC(char, len + 1);
    if (fread((void *)ret, 1, len, fp) != len) {
      log_error("Could not read file contents");
      return NULL;
    }
    ret[ *sz = len] = '\0';
    return ret;
  }

  return NULL;
}

static size_t regex_matched_len(regex_t *patt, const char *str, size_t len) {
  regmatch_t matches[1];

  if (regexec(patt, str, 1, matches, 0) == 0) {
    return matches[0].rm_eo - matches->rm_so;
  }

  return 0;
}

static void append_token(struct w_lexer *lexer, w_token_type_t type,
                         const char *text, size_t len) {
  struct w_token *tok = w_token_new(type, text, len, lexer->lines_count,
                                    lexer->tokens_count++, NULL);

  if (lexer->tokens_head == NULL) {
    lexer->tokens_head = lexer->tokens_tail = tok;
  } else {
    lexer->tokens_tail->next = tok;
    lexer->tokens_tail       = tok;
  }
}

static bool append_if_valid(struct w_lexer *lexer, const char *text, size_t len,
                            const char *str, w_token_type_t type) {
  if (strncmp(text, str, len) == 0) {
    append_token(lexer, type, text, len);
    return true;
  }

  return false;
}

int w_lexer_init(struct w_lexer *lexer) {
  assert(lexer != NULL);

  memset((void *)lexer, 0, sizeof(*lexer));
  return 0;
}

int w_lexer_scan(struct w_lexer *lexer, FILE *fp) {
  char * buf, *ptr;
  size_t len, toksz;

  regex_t    ident_patt, str_patt, num_patt;
  regmatch_t mat[1];

  if (!(buf = read_to_end(fp, &len))) {
    return -1;
  }

  regcomp(&ident_patt, "^[a-zA-Z_]+[_a-zA-Z0-9]*", REG_EXTENDED | REG_ICASE);
  regcomp(&str_patt, "^\"[^\"]+\"", REG_EXTENDED);
  regcomp(&num_patt, "^[0-9]+", REG_EXTENDED);

  for (ptr = buf; *ptr; ++ptr, --len) {
    if (*ptr == ' ' || *ptr == '\t') {
      continue;
    } else if (*ptr == '\n') {
      ++lexer->lines_count;
      continue;
    }

    if ((toksz = regex_matched_len(&str_patt, ptr, len)) > 0) {
      append_token(lexer, WILLOW_TOK_CHAR_LITERAL, ptr, toksz);
      ptr += toksz - 1;
      len -= toksz - 1;
    } else if ((toksz = regex_matched_len(&num_patt, ptr, len)) > 0) {
      append_token(lexer, WILLOW_TOK_NUMBER, ptr, toksz);
      ptr += toksz - 1;
      len -= toksz - 1;
    } else if ((toksz = regex_matched_len(&ident_patt, ptr, len)) > 0) {
      if (!(append_if_valid(lexer, ptr, toksz, "manager", WILLOW_TOK_MANAGER) ||
            append_if_valid(lexer, ptr, toksz, "private", WILLOW_TOK_PRIVATE) ||
            append_if_valid(lexer, ptr, toksz, "public", WILLOW_TOK_PUBLIC) ||
            append_if_valid(lexer, ptr, toksz, "hollow", WILLOW_TOK_HOLLOW) ||
            append_if_valid(lexer, ptr, toksz, "return", WILLOW_TOK_RETURN) ||
            append_if_valid(lexer, ptr, toksz, "loop", WILLOW_TOK_LOOP) ||
            append_if_valid(lexer, ptr, toksz, "set", WILLOW_TOK_SET) ||
            append_if_valid(lexer, ptr, toksz, "check", WILLOW_TOK_CHECK) ||
            append_if_valid(lexer, ptr, toksz, "else", WILLOW_TOK_ELSE) ||
            append_if_valid(lexer, ptr, toksz, "pare", WILLOW_TOK_PARE) ||
            append_if_valid(lexer, ptr, toksz, "compare", WILLOW_TOK_COMPARE) ||
            append_if_valid(lexer, ptr, toksz, "log", WILLOW_TOK_LOG) ||
            append_if_valid(lexer, ptr, toksz, "bridge", WILLOW_TOK_BRIDGE) ||
            append_if_valid(lexer, ptr, toksz, "act", WILLOW_TOK_ACT) ||
            append_if_valid(lexer, ptr, toksz, "internal",
                            WILLOW_TOK_INTERNAL) ||
            append_if_valid(lexer, ptr, toksz, "static", WILLOW_TOK_STATIC) ||
            append_if_valid(lexer, ptr, toksz, "register",
                            WILLOW_TOK_REGISTER) ||
            append_if_valid(lexer, ptr, toksz, "num", WILLOW_TOK_NUM) ||
            append_if_valid(lexer, ptr, toksz, "short", WILLOW_TOK_SHORT) ||
            append_if_valid(lexer, ptr, toksz, "long", WILLOW_TOK_LONG) ||
            append_if_valid(lexer, ptr, toksz, "signed", WILLOW_TOK_SIGNED) ||
            append_if_valid(lexer, ptr, toksz, "unsigned",
                            WILLOW_TOK_UNSIGNED) ||
            append_if_valid(lexer, ptr, toksz, "read", WILLOW_TOK_READ) ||
            append_if_valid(lexer, ptr, toksz, "write", WILLOW_TOK_WRITE))) {
        append_token(lexer, WILLOW_TOK_IDENT, ptr, toksz);
      }
      ptr += toksz - 1;
      len -= toksz - 1;
    } else if (append_if_valid(lexer, ptr, 2, "++", WILLOW_TOK_INC) ||
               append_if_valid(lexer, ptr, 2, "--", WILLOW_TOK_DEC) ||
               append_if_valid(lexer, ptr, 2, "->", WILLOW_TOK_RIGHT_ARROW) ||
               append_if_valid(lexer, ptr, 2, "==", WILLOW_TOK_EQUAL) ||
               append_if_valid(lexer, ptr, 2, "!=", WILLOW_TOK_NOT_EQUAL) ||
               append_if_valid(lexer, ptr, 2, "<=", WILLOW_TOK_LESS_EQUAL) ||
               append_if_valid(lexer, ptr, 2, "<-", WILLOW_TOK_LEFT_ARROW) ||
               append_if_valid(lexer, ptr, 2, ">=", WILLOW_TOK_GREATER_EQUAL) ||
               append_if_valid(lexer, ptr, 2, "--", WILLOW_TOK_ADD)) {
      ++ptr;
      --len;
    } else if (!(append_if_valid(lexer, ptr, 1, "+", WILLOW_TOK_ADD) ||
                 append_if_valid(lexer, ptr, 1, "-", WILLOW_TOK_SUB) ||
                 append_if_valid(lexer, ptr, 1, "*", WILLOW_TOK_MUL) ||
                 append_if_valid(lexer, ptr, 1, "/", WILLOW_TOK_DIV) ||
                 append_if_valid(lexer, ptr, 1, "%", WILLOW_TOK_MOD) ||
                 append_if_valid(lexer, ptr, 1, ":", WILLOW_TOK_COLON) ||
                 append_if_valid(lexer, ptr, 1, ";", WILLOW_TOK_SEMICOLON) ||
                 append_if_valid(lexer, ptr, 1, ".", WILLOW_TOK_PERIOD) ||
                 append_if_valid(lexer, ptr, 1, ",", WILLOW_TOK_COMMA) ||
                 append_if_valid(lexer, ptr, 1, "=", WILLOW_TOK_ASSIGN) ||
                 append_if_valid(lexer, ptr, 1, "<", WILLOW_TOK_LESS) ||
                 append_if_valid(lexer, ptr, 1, ">", WILLOW_TOK_GREATER) ||
                 append_if_valid(lexer, ptr, 1, "#", WILLOW_TOK_HASH) ||
                 append_if_valid(lexer, ptr, 1, "(", WILLOW_TOK_LEFT_PAREN) ||
                 append_if_valid(lexer, ptr, 1, ")", WILLOW_TOK_RIGHT_PAREN) ||
                 append_if_valid(lexer, ptr, 1, "{", WILLOW_TOK_LEFT_BRACE) ||
                 append_if_valid(lexer, ptr, 1, "}", WILLOW_TOK_RIGHT_BRACE) ||
                 append_if_valid(lexer, ptr, 1, "[", WILLOW_TOK_LEFT_BRACKET) ||
                 append_if_valid(lexer, ptr, 1, "]",
                                 WILLOW_TOK_RIGHT_BRACKET))) {
      log_error("Lexical Error: Invalid symbole encountered '%c'", *ptr);

      regfree(&ident_patt);
      regfree(&str_patt);
      regfree(&num_patt);

      return -1;
    }
  }

  regfree(&ident_patt);
  regfree(&str_patt);
  regfree(&num_patt);

  return 0;
}
