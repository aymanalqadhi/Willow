#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "type.h"


void preprocess_error(const char * m, int line_num, int token_num)
{
	printf(" preprocess_error: error type->%s->line %03d:   token %03d:  \n", m, line_num, token_num);
	exit(1);
}

void lexical_error(const char * m, int line_num, int token_num)
{
	printf(" lexical_error: error type->%s->line %03d:   token %03d:  \n", m, line_num, token_num);
	exit(1);
}

void parser_error(const char * m, int line_num, int token_num)
{
	printf(" lexical_error: error type->%s->line %03d:   token %03d:  \n", m, line_num, token_num);
	exit(1);
}

void symbol_table_error(const char * m, int line_num, int token_num)
{
	printf(" lexical_error: error type->%s->line %03d:   token %03d:  \n", m, line_num, token_num);
	exit(1);
}

void syntax_error(const char * m, int line_num, int token_num)
{
	printf(" lexical_error: error type->%s->line %03d:   token %03d:  \n", m, line_num, token_num);
	exit(1);
}

void data_type_error(const char * m, int line_num, int token_num)
{
	printf(" lexical_error: error type->%s->line %03d:   token %03d:  \n", m, line_num, token_num);
	exit(1);
}

void file_error(const char * m, int line_num, int token_num)
{
	printf(" file_error: error type->%s->line %03d:   token %03d:  \n", m, line_num, token_num);
	exit(1);
}
