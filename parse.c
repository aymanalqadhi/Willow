#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "type.h"
#include "errors.h"



void advance_token(parser *parsing_ptr)
{
	//destroy_token(parsing_ptr->live_token);
	parsing_ptr->live_token = retrieve_tokens(parsing_ptr->source.file);
}

parse(parser *parsing_ptr)
{

	while(parsing_ptr->live_token.record != _enfi)
	{
		advance_token(parsing_ptr);

		if (parsing_ptr->live_token.record == _ident)
		{
			match(parsing_ptr, _ident);

			if (parsing_ptr->live_token.record == _manager)
			{
				match(parsing_ptr, _manager);

				begin_manager(parsing_ptr);
			}
		}
	}
}


void match(parser *parsing_ptr, token_type expected)
{
	lex *source = &source;

	if(parsing_ptr->live_token.record == expected)
	{
		advance_token(parsing_ptr);
	}
	//print_token(parsing_ptr->live_token);
}


begin_manager(parser *parsing_ptr)
{
   //function to open a header file
	printf("test to see if begin_header function is being entered\n");
}

