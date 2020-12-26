#ifndef ERRORS_H_
#define ERRORS_H_


void preprocess_error(const char * m, int line_num, int token_num);
void lexical_error(const char * m, int line_num, int token_num);
void parser_error(const char * m, int line_num, int token_num);
void symbol_table_error(const char * m, int line_num, int token_num);
void syntax_error(const char * m, int line_num, int token_num);
void data_type_error(const char * m, int line_num, int token_num);
void file_error(const char * m, int line_num, int token_num);

#endif
