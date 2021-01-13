#include "willow/lexer/token.h"
#include "willow/logger.h"
#include "willow/memory.h"

#include <assert.h>
#include <stddef.h>

static const char *printable_tokes[] = {
    [WILLOW_TOK_NONE]           = "",
    [WILLOW_TOK_DONE]           = "",
    [WILLOW_TOK_NEWLINE]        = "",
    [WILLOW_TOK_SPACE]          = "",
    [WILLOW_TOK_EOF]            = "",
    [WILLOW_TOK_NUMBER]         = "number",
    [WILLOW_TOK_ADD]            = "addition operator",
    [WILLOW_TOK_SUB]            = "subtraction operator",
    [WILLOW_TOK_MUL]            = "multiplication operator",
    [WILLOW_TOK_DIV]            = "division operator",
    [WILLOW_TOK_INC]            = "increment operator",
    [WILLOW_TOK_DEC]            = "decrement operator",
    [WILLOW_TOK_HASH]           = "hash",
    [WILLOW_TOK_COLON]          = "colon",
    [WILLOW_TOK_COMMA]          = "comma",
    [WILLOW_TOK_SEMICOLON]      = "semicolon",
    [WILLOW_TOK_PERIOD]         = "period",
    [WILLOW_TOK_LEFT_PAREN]     = "lparen",
    [WILLOW_TOK_RIGHT_PAREN]    = "rparen",
    [WILLOW_TOK_LEFT_BRACE]     = "lbrace",
    [WILLOW_TOK_RIGHT_BRACE]    = "rbrace",
    [WILLOW_TOK_LEFT_BRACKET]   = "lbracket",
    [WILLOW_TOK_RIGHT_BRACKET]  = "rbracket",
    [WILLOW_TOK_LEFT_ARROW]     = "larrow",
    [WILLOW_TOK_RIGHT_ARROW]    = "rarrow",
    [WILLOW_TOK_WORD]           = "word",
    [WILLOW_TOK_IDENT]          = "ident",
    [WILLOW_TOK_KEYWORD]        = "keyword",
    [WILLOW_TOK_GREATER_EQUAL]  = "great_equal",
    [WILLOW_TOK_LESS_EQUAL]     = "less_equal",
    [WILLOW_TOK_EQUAL]          = "equal",
    [WILLOW_TOK_NOT_EQUAL]      = "not_equal",
    [WILLOW_TOK_ASSIGN]         = "assign",
    [WILLOW_TOK_CHAR_LITERAL]   = "char_literal",
    [WILLOW_TOK_STRAND_LITERAL] = "strand_literal",
    [WILLOW_TOK_CONST_LITERAL]  = "constant_literal",
    [WILLOW_TOK_MANAGER]        = "manager",
    [WILLOW_TOK_PRIVATE]        = "private",
    [WILLOW_TOK_PUBLIC]         = "public",
    [WILLOW_TOK_ELEM]           = "elem",
    [WILLOW_TOK_OBJECT]         = "object",
    [WILLOW_TOK_HOLLOW]         = "hollow",
    [WILLOW_TOK_NUM]            = "num",
    [WILLOW_TOK_MARK]           = "mark",
    [WILLOW_TOK_DECI]           = "deci",
    [WILLOW_TOK_PLACEHOLDER]    = "placeholder",
    [WILLOW_TOK_RETURN]         = "return",
    [WILLOW_TOK_FILE]           = "file",
    [WILLOW_TOK_READ]           = "read",
    [WILLOW_TOK_WRITE]          = "write",
    [WILLOW_TOK_LOOP]           = "loop",
    [WILLOW_TOK_SET]            = "set",
    [WILLOW_TOK_CHECK]          = "check",
    [WILLOW_TOK_ELSE]           = "else",
    [WILLOW_TOK_PARE]           = "pare",
    [WILLOW_TOK_COMPARE]        = "compare",
    [WILLOW_TOK_LIST]           = "list",
    [WILLOW_TOK_CONSTRUCT]      = "construct",
    [WILLOW_TOK_LOG]            = "log",
    [WILLOW_TOK_BRIDGE]         = "bridge",
    [WILLOW_TOK_ACT]            = "act",
    [WILLOW_TOK_INTERNAL]       = "internal",
    [WILLOW_TOK_STATIC]         = "static",
    [WILLOW_TOK_REGISTER]       = "register",
    [WILLOW_TOK_SHORT]          = "short",
    [WILLOW_TOK_LONG]           = "long",
    [WILLOW_TOK_SIGNED]         = "signed",
    [WILLOW_TOK_UNSIGNED]       = "unsigned",
};

struct w_token *w_token_new(w_token_type_t type, const char *text_buffer,
                            size_t line_num, size_t token_num) {
  struct w_token *tok = W_MALLOC(struct w_token, 1);

  tok->type        = type;
  tok->text_buffer = text_buffer;
  tok->line_num    = line_num;
  tok->token_num   = token_num;

  return tok;
}

void w_token_free(struct w_token *tok) {
  assert(tok != NULL);
  w_free((void *)tok);
}

void w_token_print(const struct w_token *tok) {
  log_info("%03d:%03d: %s \t %s", tok->line_num, tok->token_num,
           tok->text_buffer, printable_tokes[tok->type]);
}

