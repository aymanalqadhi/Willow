#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "type.h"
#include "check_words.h"
#include "errors.h"
#include "parse.h"

int main()
{

	if ((source.file = fopen("willow.w", "r")) == NULL)          
	{
		file_error("file error: error opening  the program file", 0, 0);                      
		exit(1);
  }

	while (true)
	{
		token build = retrieve_tokens(&source);

		if (build.record == _enfi)
		{
			destroy_token(build);
			break;
		}
		print_token(build);
		destroy_token(build);
	}
  
	parser parsing = { .source = &source };
	parse(&parsing);

	fclose(source.file);
	return 0;
}

token create_token(token_type record, int line_num, int token_num, const char *lexer_buffer, int length)
{
	token build_token;

	char *text_buffer = malloc(length + 1);

	if (!text_buffer)
	{
		lexical_error(" lexing buffer error: ran out of memory allocating the token", line_num, token_num);
	}

	memcpy(text_buffer, lexer_buffer, length);
	text_buffer[length] = '\0';

	build_token.record = record;
	build_token.line_num = line_num;
	build_token.token_num = token_num;
	build_token.text_buffer = text_buffer;

	return build_token;
}

void destroy_token(token build_token)
{
	free((void *)build_token.text_buffer);
}

token retrieve_tokens(lex *source)
{
	const int line_num = ++source->line_num;
	const int token_num = ++source->token_num;

	int length = 0;
	int ch = 0;
	int ch_two = 0;
	int check = 0;

	if ((ch = fgetc(source->file)) == EOF)
	{
		return create_token(_enfi, line_num, token_num, lexer_buffer, 0);
	}

	lexer_buffer[length++] = ch;

	switch (ch)
	{
	case '\n': source->line_num--; return create_token(_neli, line_num, token_num, lexer_buffer, 0);
	case ' ':  source->line_num--; return create_token(_space, line_num, token_num, lexer_buffer, length);
	

	case '#':   return create_token(_hash, line_num, token_num, lexer_buffer, length);
	case ':':   return create_token(_colon, line_num, token_num, lexer_buffer, length);
	case '.':   return create_token(_period, line_num, token_num, lexer_buffer, length);
	case ',':   return create_token(_comma, line_num, token_num, lexer_buffer, length);
	case ';':   return create_token(_semicolon, line_num, token_num, lexer_buffer, length);

	case '(':   return create_token(_lparen, line_num, token_num, lexer_buffer, length);
	case ')':   return create_token(_rparen, line_num, token_num, lexer_buffer, length);
	case '{':   return create_token(_lbracket, line_num, token_num, lexer_buffer, length);
	case '}':   return create_token(_rbracket, line_num, token_num, lexer_buffer, length);
	case '[':   return create_token(_lbrace, line_num, token_num, lexer_buffer, length);
	case ']':   return create_token(_rbrace, line_num, token_num, lexer_buffer, length);


	case '<': 
	{
		ch_two = fgetc(source->file);
	
		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_l_equal, line_num, token_num, lexer_buffer, length);
		}
		ungetc(ch_two, source->file);
		return create_token(_larrow, line_num, token_num, lexer_buffer, length);
	}

	case '>':
	{
		ch_two = fgetc(source->file);

		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_g_equal, line_num, token_num, lexer_buffer, length);
		}
		ungetc(ch_two, source->file);
		return create_token(_rarrow, line_num, token_num, lexer_buffer, length);
	}

	case '!':
	{
		ch_two = fgetc(source->file);

		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_not_equal, line_num, token_num, lexer_buffer, length);
		}
		break;
	}

	case '=':
	{
		ch_two = fgetc(source->file);

		if (ch_two == '=')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_equal, line_num, token_num, lexer_buffer, length);
		}
		ungetc(ch_two, source->file);
		return create_token(_assign, line_num, token_num, lexer_buffer, length);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	case '0' <= '9':  return create_token(_number, line_num, token_num, lexer_buffer, length);


	case '%':         return create_token(_modulo, line_num, token_num, lexer_buffer, length);
	case '*':         return create_token(_multiply, line_num, token_num, lexer_buffer, length);
	case '/':         return create_token(_divide, line_num, token_num, lexer_buffer, length);
	case '+':
	{
		ch_two = fgetc(source->file);

		if (ch_two == '+')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_increment, line_num, token_num, lexer_buffer, length);
		}
		ungetc(ch_two, source->file);
		return create_token(_addition, line_num, token_num, lexer_buffer, length);
	}
	case '-':
	{
		ch_two = fgetc(source->file);

		if (ch_two == '-')
		{
			lexer_buffer[length++] = ch_two;
			return create_token(_decrement, line_num, token_num, lexer_buffer, length);
		}
		ungetc(ch_two, source->file);
		return create_token(_subtract, line_num, token_num, lexer_buffer, length);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	

	default:   break;
	}


	if (ch == '"')
	{
		while (ch_two != '"')
		{
			ch_two = fgetc(source->file);

			if (ch_two == '"')
			{
				lexer_buffer[length] = 0;
			}
			lexer_buffer[length++] = ch_two;
		}
		return create_token(_strand_literal, line_num, token_num, lexer_buffer, length);
	}

	while ((ch = fgetc(source->file)) != EOF && length < max_buffer_elem)
	{
		if (!letter(ch))
		{
			ungetc(ch, source->file);
			break;
		}
		lexer_buffer[length++] = ch;
	}

	if (length >= max_buffer_elem)
	{
		lexical_error("lexical buffer error: token exceeds maximum length", line_num, token_num);
	}

	lexer_buffer[length] = 0;


	token build_token = create_token(_word, line_num, token_num, lexer_buffer, length);

	if (check_word(&build_token))
	{
		return build_token;
	}
	if (check_ident(&build_token))
	{
		return build_token;
	}
}

void print_token(token build_token)
{
	const char *text_buffer = build_token.text_buffer;
	const int line_num = build_token.line_num;
	const int token_num = build_token.token_num;

	switch (build_token.record)
	{
	case _space:                                    break;
	case _neli:                                     break;

	case _ident:              printf(" %03d:  %03d:  %s\t                          ident\n", line_num, token_num, text_buffer);                             break;
	case _strand_literal:     printf(" %03d:  %03d:  %s\t                  strand_literal\n", line_num, token_num, text_buffer);                  break;

	case _number:             printf(" %03d:  %03d:  %s\t                          number\n", line_num, token_num, text_buffer);                            break;
	case _addition:           printf(" %03d:  %03d:  %s\t                          addition operator\n", line_num, token_num, text_buffer);                 break;
	case _subtract:           printf(" %03d:  %03d:  %s\t                          subtract operator\n", line_num, token_num, text_buffer);                 break;
	case _multiply:           printf(" %03d:  %03d:  %s\t                          multiply operator\n", line_num, token_num, text_buffer);                 break;
	case _divide:             printf(" %03d:  %03d:  %s\t                          divide operator\n", line_num, token_num, text_buffer);                   break;
	case _increment:          printf(" %03d:  %03d:  %s\t                          increment operator\n", line_num, token_num, text_buffer);                break;
	case _decrement:          printf(" %03d:  %03d:  %s\t                          decrement operator\n", line_num, token_num, text_buffer);                break;
	

	case _g_equal:            printf(" %03d:  %03d:  %s\t                          great_equal\n", line_num, token_num, text_buffer);                       break;
	case _l_equal:            printf(" %03d:  %03d:  %s\t                          less_equal\n", line_num, token_num, text_buffer);                        break;
	case _not_equal:          printf(" %03d:  %03d:  %s\t                          not_equal\n", line_num, token_num, text_buffer);                         break;
	case _equal:              printf(" %03d:  %03d:  %s\t                          equal\n", line_num, token_num, text_buffer);                             break;
	case _assign:             printf(" %03d:  %03d:  %s\t                          assign operator\n", line_num, token_num, text_buffer);                   break;


	case _lparen:             printf(" %03d:  %03d:  %s\t                          lparen operator\n", line_num, token_num, text_buffer);                   break;
	case _rparen:             printf(" %03d:  %03d:  %s\t                          rparen operator\n", line_num, token_num, text_buffer);                   break;
	case _lbracket:           printf(" %03d:  %03d:  %s\t                          lbracket operator\n", line_num, token_num, text_buffer);                 break;
	case _rbracket:           printf(" %03d:  %03d:  %s\t                          rbracket operator\n", line_num, token_num, text_buffer);                 break;
	case _lbrace:             printf(" %03d:  %03d:  %s\t                          lbrace operator\n", line_num, token_num, text_buffer);                   break;
	case _rbrace:             printf(" %03d:  %03d:  %s\t                          rbrace operator\n", line_num, token_num, text_buffer);                   break;
	case _larrow:             printf(" %03d:  %03d:  %s\t                          larrow operator\n", line_num, token_num, text_buffer);                   break;
	case _rarrow:             printf(" %03d:  %03d:  %s\t                          rarrow operator\n", line_num, token_num, text_buffer);                   break;

	case _colon:              printf(" %03d:  %03d:  %s\t                          colon operator\n", line_num, token_num, text_buffer);                    break;
	case _comma:              printf(" %03d:  %03d:  %s\t                          comma operator\n", line_num, token_num, text_buffer);                    break;
	case _period:             printf(" %03d:  %03d:  %s\t                          period operator\n", line_num, token_num, text_buffer);                   break;
	case _semicolon:          printf(" %03d:  %03d:  %s\t                          semicolon operator\n", line_num, token_num, text_buffer);                break;

	case _use:                printf(" %03d:  %03d:  %s\t                  use header\n", line_num, token_num, text_buffer);                        break;
	case _link:               printf(" %03d:  %03d:  %s\t                  link header\n", line_num, token_num, text_buffer);                       break;
	case _translate:          printf(" %03d:  %03d:  %s\t                  translate header\n", line_num, token_num, text_buffer);                  break;
	case _system:             printf(" %03d:  %03d:  %s\t                  system header\n", line_num, token_num, text_buffer);                     break;
	case _haven:              printf(" %03d:  %03d:  %s\t                  haven header\n", line_num, token_num, text_buffer);                      break;
	case _io:                 printf(" %03d:  %03d:  %s\t                  io header\n", line_num, token_num, text_buffer);                         break;

	case _manager:            printf(" %03d:  %03d:  %s\t                  manager\n", line_num, token_num, text_buffer);                           break;
	case _private:            printf(" %03d:  %03d:  %s\t                  private\n", line_num, token_num, text_buffer);                           break;
	case _public:             printf(" %03d:  %03d:  %s\t                  public\n", line_num, token_num, text_buffer);                            break;
	case _elem:               printf(" %03d:  %03d:  %s\t                  elem\n", line_num, token_num, text_buffer);                              break;
	case _object:             printf(" %03d:  %03d:  %s\t                  object\n", line_num, token_num, text_buffer);                            break;

	case _read:               printf(" %03d:  %03d:  %s\t                  read function\n", line_num, token_num, text_buffer);                     break;
	case _write:              printf(" %03d:  %03d:  %s\t                  write function\n", line_num, token_num, text_buffer);                    break;

	case _file:               printf(" %03d:  %03d:  %s\t                  file\n", line_num, token_num, text_buffer);                              break;
	case _hollow:             printf(" %03d:  %03d:  %s\t                  hollow\n", line_num, token_num, text_buffer);                            break;
	case _num:                printf(" %03d:  %03d:  %s\t                  num\n", line_num, token_num, text_buffer);                               break;
	case _deci:               printf(" %03d:  %03d:  %s\t                  deci\n", line_num, token_num, text_buffer);                              break;
	case _mark:               printf(" %03d:  %03d:  %s\t                  mark\n", line_num, token_num, text_buffer);                              break;
	case _return:             printf(" %03d:  %03d:  %s\t                  return\n", line_num, token_num, text_buffer);                            break;

	case _check:              printf(" %03d:  %03d:  %s\t                  check\n", line_num, token_num, text_buffer);                             break;
	case _else:               printf(" %03d:  %03d:  %s\t                  else\n", line_num, token_num, text_buffer);                              break;
	case _loop:               printf(" %03d:  %03d:  %s\t                  loop\n", line_num, token_num, text_buffer);                              break;
	case _set:                printf(" %03d:  %03d:  %s\t                  set\n", line_num, token_num, text_buffer);                               break;
	case _pare:               printf(" %03d:  %03d:  %s\t                  pare\n", line_num, token_num, text_buffer);                              break;
	case _compare:            printf(" %03d:  %03d:  %s\t                  compare\n", line_num, token_num, text_buffer);                           break;
	case _list:               printf(" %03d:  %03d:  %s\t                  list\n", line_num, token_num, text_buffer);                              break;
	case _construct:          printf(" %03d:  %03d:  %s\t                  construct\n", line_num, token_num, text_buffer);                         break;
	case _log:                printf(" %03d:  %03d:  %s\t                  log\n", line_num, token_num, text_buffer);                               break;
	case _bridge:             printf(" %03d:  %03d:  %s\t                  bridge\n", line_num, token_num, text_buffer);                            break;

	case _short:              printf(" %03d:  %03d:  %s\t                  short\n", line_num, token_num, text_buffer);                             break;
	case _long:               printf(" %03d:  %03d:  %s\t                  long\n", line_num, token_num, text_buffer);                              break;
	case _signed:             printf(" %03d:  %03d:  %s\t                  signed\n", line_num, token_num, text_buffer);                            break;
	case _unsigned:           printf(" %03d:  %03d:  %s\t                  unsigned\n", line_num, token_num, text_buffer);                          break;
	case _static:             printf(" %03d:  %03d:  %s\t                  static\n", line_num, token_num, text_buffer);                            break;
	case _external:           printf(" %03d:  %03d:  %s\t                  external\n", line_num, token_num, text_buffer);                          break;
	case _internal:           printf(" %03d:  %03d:  %s\t                  internal\n", line_num, token_num, text_buffer);                          break;
	case _register:           printf(" %03d:  %03d:  %s\t                  register\n", line_num, token_num, text_buffer);                          break;


	case _enfi:               printf(" %03d:  %03d:  %s\t                                 enfi\n", line_num, token_num, text_buffer);                break;

	default:                  lexical_error("Unknown Token:  unknown token in the print_token function", line_num, token_num);                       break;
	}
}



