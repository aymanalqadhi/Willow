#ifndef PARSE_H_
#define PARSE_H_

#include "type.h"

parse(parser *parsing_ptr);
void match(parser *parsing_ptr, token_type expected);

#endif /* PARSE_H_ */
