#include "willow/error.h"

const char *w_strerror(w_error_t err) {
  switch (err) {
  case WILLOW_ERR_SUCESS:
    return "success";
  case WILLOW_ERR_PREPROCESS:
    return "preprocessor error";
  case WILLOW_ERR_LEXICAL:
    return "lexical error";
  case WILLOW_ERR_PARSER:
    return "parser error";
  case WILLOW_ERR_SYMBOLE_TABLE:
    return "symbole table error";
  case WILLOW_ERR_SYNTAX:
    return "syntax error";
  case WILLOW_ERR_DATA_TYPE:
    return "data type error";
  case WILLOW_ERR_FILE:
    return "file error";
  default:
    return "unknown error";
  }
}
