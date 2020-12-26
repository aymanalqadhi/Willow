#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "type.h"

struct entry preprocess_header[] = { {"use", _use},{"define", _define },{ "link",_link },{"translate", _translate} };
struct entry system_header[] = { { "system",_system} };
struct entry sub_header[] = { { "haven", _haven},{ "io", _io} };

struct entry file_type[] = { { "file", _file} };

struct entry manager_type[] = { { "manager",_manager },{ "private",_private},{ "public",_public},{ "elem",_elem},{ "object", _object} };
struct entry function_type[] = { { "read",_read}, { "write", _write} };

struct entry data_type[] = { { "hollow",_hollow}, { "num", _num},{ "mark",_mark},{ "deci",_deci},{ "return", _return}, {"hold", _placeholder} };
struct entry data_tools[] = { { "loop",_loop},{"set",_set},{"check",_check},{"else",_else},{"pare",_pare},{"compare",_compare},{"list",_list},{"construct",_construct},{"log",_log},{ "bridge", _bridge},{"act",_act} };
struct entry data_modifier[] = { { "extern",_external},{"intern",_internal},{ "static",_static},{"register",_register},{"short", _short},{ "long",_long},{ "signed",_signed},{ "unsigned",_unsigned} };
struct entry assign_type[] = { {"assign", _assign} };



int upper(int ch) { return (ch >= 'A') && (ch <= 'Z'); }
int lower(int ch) { return (ch >= 'a') && (ch <= 'z'); }
int under_score(int ch) { return (ch == '_'); }
int letter(int ch) { return (upper(ch) || lower(ch) || under_score(ch)); }
