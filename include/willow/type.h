#ifndef TYPE_H_
#define TYPE_H_


typedef enum
{
	_none, _done,

	//preprocessor associated
	_seedling, _link, _use, _define, _translate, _system, _haven, _io,

	//new_line, space, end_file
	_neli, _space, _enfi,

	//number associated tokens
	_number, _addition, _subtract, _multiply, _divide, _increment, _decrement, _modulo,

	//seperating associated tokens
	_hash, _colon, _comma, _semicolon, _period,

	//grouping associated tokens
	_lparen, _rparen, _lbrace, _rbrace, _lbracket, _rbracket, _larrow, _rarrow,

	//work making associated tokens
	_word, _ident, _keyword,

	//equalizers or relational associated tokens
	_g_equal, _l_equal, _equal, _not_equal, _assign,

	//literal associated tokens
	_char_literal, _strand_literal, _constant_literal,

	//manager or class making associated tokens
	_manager, _private, _public, _elem, _object,

	//data type associated tokens
	_hollow, _num, _mark, _deci, _placeholder, _return,

	//file related associated tokens
	_file, _read, _write,

	// statement tokens / data tool tokens
	_loop, _set, _check, _else, _pare, _compare, _list, _construct, _log, _bridge, _act,


	_external, _internal, _static, _register, _short, _long, _signed, _unsigned,

}token_type;

struct entry
{
	char *str_ptr;
	token_type enum_tokens;
};

extern struct entry preprocess_header[];
extern struct entry system_header[];
extern struct entry sub_header[];

extern struct entry file_type[];

extern struct entry manager_type[];
extern struct entry function_type[];


extern struct entry data_type[];
extern struct entry data_tools[];
extern struct entry data_modifier[];
extern struct entry assign_type[];

typedef struct token
{
	token_type record;
	const char *text_buffer;
	int        line_num;
	int        token_num;
} token;

typedef struct lex
{
	FILE *file;
	int   line_num;
	int   token_num;
} lex;


typedef struct parser
{
	lex source;
	token live_token;
} parser;



char lexer_buffer[1000];

extern token create_token(token_type record, int line_num, int token_num, const char *lexer_buffer, int length);
extern void destroy_token(token build_token);
extern token retrieve_tokens(lex * source);
extern void print_token(token);
extern bool check_word(token *build_token);
extern bool check_ident(token *build_token);

#endif /* TYPE_H_ */
