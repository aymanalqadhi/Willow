#ifndef WILLOW_LEXER_TOKEN_H
#define WILLOW_LEXER_TOKEN_H

#include <stddef.h>

typedef enum
{
  WILLOW_TOK_NONE,
  WILLOW_TOK_DONE,

  /* Preprocessor associated */
  WILLOW_TOK_NEWLINE,
  WILLOW_TOK_SPACE,
  WILLOW_TOK_EOF,

  /* Number associated tokens */
  WILLOW_TOK_NUMBER,
  WILLOW_TOK_ADD,
  WILLOW_TOK_SUB,
  WILLOW_TOK_MUL,
  WILLOW_TOK_DIV,
  WILLOW_TOK_INC,
  WILLOW_TOK_DEC,
  WILLOW_TOK_MOD,

  /* Separating associated tokens */
  WILLOW_TOK_HASH,
  WILLOW_TOK_COLON,
  WILLOW_TOK_COMMA,
  WILLOW_TOK_SEMICOLON,
  WILLOW_TOK_PERIOD,

  /* Grouping associated tokens */
  WILLOW_TOK_LEFT_PAREN,
  WILLOW_TOK_RIGHT_PAREN,
  WILLOW_TOK_LEFT_BRACE,
  WILLOW_TOK_RIGHT_BRACE,
  WILLOW_TOK_LEFT_BRACKET,
  WILLOW_TOK_RIGHT_BRACKET,
  WILLOW_TOK_LEFT_ARROW,
  WILLOW_TOK_RIGHT_ARROW,

  /* Work-making associated tokens */
  WILLOW_TOK_WORD,
  WILLOW_TOK_IDENT,
  WILLOW_TOK_KEYWORD,

  /* Equalizer or relational associated tokens */
  WILLOW_TOK_GREATER,
  WILLOW_TOK_GREATER_EQUAL,
  WILLOW_TOK_LESS,
  WILLOW_TOK_LESS_EQUAL,
  WILLOW_TOK_EQUAL,
  WILLOW_TOK_NOT_EQUAL,
  WILLOW_TOK_ASSIGN,

  /* Literal associated tokens */
  WILLOW_TOK_CHAR_LITERAL,
  WILLOW_TOK_STRAND_LITERAL,
  WILLOW_TOK_CONST_LITERAL,

  /* Manager/class making associated tokens */
  WILLOW_TOK_MANAGER,
  WILLOW_TOK_PRIVATE,
  WILLOW_TOK_PUBLIC,
  WILLOW_TOK_ELEM,
  WILLOW_TOK_OBJECT,

  /* Data-type associated tokens */
  WILLOW_TOK_HOLLOW,
  WILLOW_TOK_NUM,
  WILLOW_TOK_MARK,
  WILLOW_TOK_DECI,
  WILLOW_TOK_PLACEHOLDER,
  WILLOW_TOK_RETURN,

  /* File associated tokens */
  WILLOW_TOK_FILE,
  WILLOW_TOK_READ,
  WILLOW_TOK_WRITE,

  /* Statement tokens / data tool tokens */
  WILLOW_TOK_LOOP,
  WILLOW_TOK_SET,
  WILLOW_TOK_CHECK,
  WILLOW_TOK_ELSE,
  WILLOW_TOK_PARE,
  WILLOW_TOK_COMPARE,
  WILLOW_TOK_LIST,
  WILLOW_TOK_CONSTRUCT,
  WILLOW_TOK_LOG,
  WILLOW_TOK_BRIDGE,
  WILLOW_TOK_ACT,
  WILLOW_TOK_INTERNAL,
  WILLOW_TOK_STATIC,
  WILLOW_TOK_REGISTER,
  WILLOW_TOK_SHORT,
  WILLOW_TOK_LONG,
  WILLOW_TOK_SIGNED,
  WILLOW_TOK_UNSIGNED,
} w_token_type_t;

struct w_token {
  w_token_type_t type;

  char * text_buffer;
  size_t line_num;
  size_t token_num;

  struct w_token *next;
};

struct w_token *w_token_new(w_token_type_t type, const char *text_buffer,
                            size_t len, size_t line_num, size_t token_num,
                            struct w_token *next);

void w_token_free(struct w_token *tok);
void w_token_print(const struct w_token *tok);

#endif /* WILLOW_LEXER_TOKEN_H */
