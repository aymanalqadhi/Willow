#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "type.h"
#include "check_words.h"



bool check_word(token * build_token)
{
	int i = 0;
	const char *t = build_token->text_buffer;
	const int line_num = build_token->line_num;
	const int token_num = build_token->token_num;

	int length = 0;
	for (i = 0; i < 4; i++)
	{
		if (strcmp(preprocess_header[i].str_ptr, t) == 0)
		{
			if (strcmp(preprocess_header[i].str_ptr, "use") == 0)
			{
				build_token->record = _use;
				return true;
			}
			if (strcmp(preprocess_header[i].str_ptr, "define") == 0)
			{
				build_token->record = _define;
				return true;
			}
			if (strcmp(preprocess_header[i].str_ptr, "link") == 0)
			{
				build_token->record = _link;
				return true;
			}
			if (strcmp(preprocess_header[i].str_ptr, "translate") == 0)
			{
				build_token->record = _translate;
				return true;
			}
		}
	}
	for (i = 0; i < 1; i++)
	{
		if (strcmp(system_header[i].str_ptr, t) == 0)
		{
			if (strcmp(system_header[i].str_ptr, "system") == 0)
			{
				build_token->record = _system;
				return true;
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		if (strcmp(sub_header[i].str_ptr, t) == 0)
		{
			if (strcmp(sub_header[i].str_ptr, "haven") == 0)
			{
				build_token->record = _haven;
				return true;
			}
			if (strcmp(sub_header[i].str_ptr, "io") == 0)
			{
				build_token->record = _io;
				return true;
			}
		}
	}

	for (i = 0; i < 5; i++)
	{

		if (strcmp(manager_type[i].str_ptr, t) == 0)
		{
			if (strcmp(manager_type[i].str_ptr, "manager") == 0)
			{
				build_token->record = _manager;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "hide") == 0)
			{
				build_token->record = _private;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "show") == 0)
			{
				build_token->record = _public;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "elem") == 0)
			{
				build_token->record = _elem;
				return true;
			}
			if (strcmp(manager_type[i].str_ptr, "object") == 0)
			{
				build_token->record = _object;
				return true;
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		if (strcmp(function_type[i].str_ptr, t) == 0)
		{
			if (strcmp(function_type[i].str_ptr, "read") == 0)
			{
				build_token->record = _read;
				return true;
			}
			if (strcmp(function_type[i].str_ptr, "object") == 0)
			{
				build_token->record = _write;
				return true;
			}
		}
	}
	for (i = 0; i < 1; i++)
	{
		if (strcmp(file_type[i].str_ptr, t) == 0)
		{
			if (strcmp(file_type[i].str_ptr, "file") == 0)
			{
				build_token->record = _file;
				return true;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		if (strcmp(data_type[i].str_ptr, t) == 0)
		{
			if (strcmp(data_type[i].str_ptr, "hollow") == 0)
			{
				build_token->record = _hollow;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "num") == 0)
			{
				build_token->record = _num;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "deci") == 0)
			{
				build_token->record = _deci;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "mark") == 0)
			{
				build_token->record = _mark;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "strand") == 0)
			{
				build_token->record = _strand_literal;
				return true;
			}
			if (strcmp(data_type[i].str_ptr, "return") == 0)
			{
				build_token->record = _return;
				return true;
			}
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (strcmp(data_tools[i].str_ptr, t) == 0)
		{
			if (strcmp(data_tools[i].str_ptr, "check") == 0)
			{
				build_token->record = _check;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "else") == 0)
			{
				build_token->record = _else;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "loop") == 0)
			{
				build_token->record = _loop;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "set") == 0)
			{
				build_token->record = _set;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "pare") == 0)
			{
				build_token->record = _pare;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "compare") == 0)
			{
				build_token->record = _compare;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "list") == 0)
			{
				build_token->record = _list;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "construct") == 0)
			{
				build_token->record = _construct;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "log") == 0)
			{
				build_token->record = _log;
				return true;
			}
			if (strcmp(data_tools[i].str_ptr, "bridge") == 0)
			{
				build_token->record = _bridge;
				return true;
			}
		}
	}
	for (i = 0; i < 8; i++)
	{

		if (strcmp(data_modifier[i].str_ptr, t) == 0)
		{
			if (strcmp(data_modifier[i].str_ptr, "short") == 0)
			{
				build_token->record = _short;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "long") == 0)
			{
				build_token->record = _long;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "signed") == 0)
			{
				build_token->record = _signed;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "unsigned") == 0)
			{
				build_token->record = _unsigned;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "static") == 0)
			{
				build_token->record = _static;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "extern") == 0)
			{
				build_token->record = _external;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "extern") == 0)
			{
				build_token->record = _internal;
				return true;
			}
			if (strcmp(data_modifier[i].str_ptr, "register") == 0)
			{
				build_token->record = _register;
				return true;
			}
		}
	}
	for (i = 0; i < 1; i++)
	{
		if (strcmp(assign_type[i].str_ptr, t) == 0)
		{
			if (strcmp(assign_type[i].str_ptr, "assign") == 0)
			{
				build_token->record = _assign;
				return true;
			}
		}
	}
	return false;
}

bool check_ident(token *build_token)
{
	//insert(ident_buffer, _ident);
	build_token->record = _ident;
	return true;
}

