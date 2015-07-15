/* Generated by re2c 0.13.5 on Sun May 10 20:45:09 2015 */
// 1 "scanner.re"

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "php_phalcon.h"

#include "scanner.h"

#define AACTYPE unsigned char
#define AACURSOR (s->start)
#define AALIMIT (s->end)
#define AAMARKER q

int phannot_get_token(phannot_scanner_state *s, phannot_scanner_token *token) {

	char next, *q = AACURSOR, *start = AACURSOR;
	int status = PHANNOT_SCANNER_RETCODE_IMPOSSIBLE;

	while (PHANNOT_SCANNER_RETCODE_IMPOSSIBLE == status) {

		if (s->mode == PHANNOT_MODE_RAW) {

			if (*AACURSOR == '\n') {
				s->active_line++;
			}

			next = *(AACURSOR+1);

			if (*AACURSOR == '\0' || *AACURSOR == '@') {
				if ((next >= 'A' && next <= 'Z') || (next >= 'a' && next <= 'z')) {
					s->mode = PHANNOT_MODE_ANNOTATION;
					continue;
				}
			}

			++AACURSOR;
			token->opcode = PHANNOT_T_IGNORE;
			return 0;

		} else {

		
// 61 "scanner.c"
		{
			AACTYPE aach;
			unsigned int aaaccept = 0;

			aach = *AACURSOR;
			switch (aach) {
			case 0x00:	goto aa38;
			case '\t':
			case '\r':
			case ' ':	goto aa34;
			case '\n':	goto aa36;
			case '"':	goto aa10;
			case '\'':	goto aa11;
			case '(':	goto aa14;
			case ')':	goto aa16;
			case ',':	goto aa32;
			case '-':	goto aa2;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto aa4;
			case ':':	goto aa30;
			case '=':	goto aa28;
			case '@':	goto aa26;
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa13;
			case 'F':
			case 'f':	goto aa8;
			case 'N':
			case 'n':	goto aa6;
			case 'T':
			case 't':	goto aa9;
			case '[':	goto aa22;
			case '\\':	goto aa12;
			case ']':	goto aa24;
			case '{':	goto aa18;
			case '}':	goto aa20;
			default:	goto aa40;
			}
aa2:
			++AACURSOR;
			switch ((aach = *AACURSOR)) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto aa71;
			default:	goto aa3;
			}
aa3:
// 178 "scanner.re"
			{
			status = PHANNOT_SCANNER_RETCODE_ERR;
			break;
		}
// 173 "scanner.c"
aa4:
			aaaccept = 0;
			aach = *(AAMARKER = ++AACURSOR);
			goto aa72;
aa5:
// 62 "scanner.re"
			{
			token->opcode = PHANNOT_T_INTEGER;
			token->value = estrndup(start, AACURSOR - start);
			token->len = AACURSOR - start;
			q = AACURSOR;
			return 0;
		}
// 187 "scanner.c"
aa6:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'U':
			case 'u':	goto aa66;
			default:	goto aa44;
			}
aa7:
// 104 "scanner.re"
			{
			token->opcode = PHANNOT_T_IDENTIFIER;
			token->value = estrndup(start, AACURSOR - start);
			token->len = AACURSOR - start;
			q = AACURSOR;
			return 0;
		}
// 205 "scanner.c"
aa8:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'A':
			case 'a':	goto aa61;
			default:	goto aa44;
			}
aa9:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'R':
			case 'r':	goto aa57;
			default:	goto aa44;
			}
aa10:
			aaaccept = 2;
			aach = *(AAMARKER = ++AACURSOR);
			if (aach <= 0x00) goto aa3;
			goto aa55;
aa11:
			aaaccept = 2;
			aach = *(AAMARKER = ++AACURSOR);
			if (aach <= 0x00) goto aa3;
			goto aa50;
aa12:
			aach = *++AACURSOR;
			switch (aach) {
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa43;
			default:	goto aa3;
			}
aa13:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			goto aa44;
aa14:
			++AACURSOR;
// 112 "scanner.re"
			{
			token->opcode = PHANNOT_T_PARENTHESES_OPEN;
			return 0;
		}
// 301 "scanner.c"
aa16:
			++AACURSOR;
// 117 "scanner.re"
			{
			token->opcode = PHANNOT_T_PARENTHESES_CLOSE;
			return 0;
		}
// 309 "scanner.c"
aa18:
			++AACURSOR;
// 122 "scanner.re"
			{
			token->opcode = PHANNOT_T_BRACKET_OPEN;
			return 0;
		}
// 317 "scanner.c"
aa20:
			++AACURSOR;
// 127 "scanner.re"
			{
			token->opcode = PHANNOT_T_BRACKET_CLOSE;
			return 0;
		}
// 325 "scanner.c"
aa22:
			++AACURSOR;
// 132 "scanner.re"
			{
			token->opcode = PHANNOT_T_SBRACKET_OPEN;
			return 0;
		}
// 333 "scanner.c"
aa24:
			++AACURSOR;
// 137 "scanner.re"
			{
			token->opcode = PHANNOT_T_SBRACKET_CLOSE;
			return 0;
		}
// 341 "scanner.c"
aa26:
			++AACURSOR;
// 142 "scanner.re"
			{
			token->opcode = PHANNOT_T_AT;
			return 0;
		}
// 349 "scanner.c"
aa28:
			++AACURSOR;
// 147 "scanner.re"
			{
			token->opcode = PHANNOT_T_EQUALS;
			return 0;
		}
// 357 "scanner.c"
aa30:
			++AACURSOR;
// 152 "scanner.re"
			{
			token->opcode = PHANNOT_T_COLON;
			return 0;
		}
// 365 "scanner.c"
aa32:
			++AACURSOR;
// 157 "scanner.re"
			{
			token->opcode = PHANNOT_T_COMMA;
			return 0;
		}
// 373 "scanner.c"
aa34:
			++AACURSOR;
			aach = *AACURSOR;
			goto aa42;
aa35:
// 162 "scanner.re"
			{
			token->opcode = PHANNOT_T_IGNORE;
			return 0;
		}
// 384 "scanner.c"
aa36:
			++AACURSOR;
// 167 "scanner.re"
			{
			s->active_line++;
			token->opcode = PHANNOT_T_IGNORE;
			return 0;
		}
// 393 "scanner.c"
aa38:
			++AACURSOR;
// 173 "scanner.re"
			{
			status = PHANNOT_SCANNER_RETCODE_EOF;
			break;
		}
// 401 "scanner.c"
aa40:
			aach = *++AACURSOR;
			goto aa3;
aa41:
			++AACURSOR;
			aach = *AACURSOR;
aa42:
			switch (aach) {
			case '\t':
			case '\r':
			case ' ':	goto aa41;
			default:	goto aa35;
			}
aa43:
			aaaccept = 1;
			AAMARKER = ++AACURSOR;
			aach = *AACURSOR;
aa44:
			switch (aach) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa43;
			case '\\':	goto aa45;
			default:	goto aa7;
			}
aa45:
			++AACURSOR;
			aach = *AACURSOR;
			switch (aach) {
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa47;
			default:	goto aa46;
			}
aa46:
			AACURSOR = AAMARKER;
			switch (aaaccept) {
			case 0: 	goto aa5;
			case 1: 	goto aa7;
			case 2: 	goto aa3;
			case 3: 	goto aa60;
			case 4: 	goto aa65;
			case 5: 	goto aa69;
			}
aa47:
			aaaccept = 1;
			AAMARKER = ++AACURSOR;
			aach = *AACURSOR;
			switch (aach) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa47;
			case '\\':	goto aa45;
			default:	goto aa7;
			}
aa49:
			++AACURSOR;
			aach = *AACURSOR;
aa50:
			switch (aach) {
			case 0x00:	goto aa46;
			case '\'':	goto aa52;
			case '\\':	goto aa51;
			default:	goto aa49;
			}
aa51:
			++AACURSOR;
			aach = *AACURSOR;
			switch (aach) {
			case '\n':	goto aa46;
			default:	goto aa49;
			}
aa52:
			++AACURSOR;
// 95 "scanner.re"
			{
			token->opcode = PHANNOT_T_STRING;
			token->value = estrndup(q, AACURSOR - q - 1);
			token->len = AACURSOR - q - 1;
			q = AACURSOR;
			return 0;
		}
// 654 "scanner.c"
aa54:
			++AACURSOR;
			aach = *AACURSOR;
aa55:
			switch (aach) {
			case 0x00:	goto aa46;
			case '"':	goto aa52;
			case '\\':	goto aa56;
			default:	goto aa54;
			}
aa56:
			++AACURSOR;
			aach = *AACURSOR;
			switch (aach) {
			case '\n':	goto aa46;
			default:	goto aa54;
			}
aa57:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'U':
			case 'u':	goto aa58;
			default:	goto aa44;
			}
aa58:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'E':
			case 'e':	goto aa59;
			default:	goto aa44;
			}
aa59:
			aaaccept = 3;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa43;
			case '\\':	goto aa45;
			default:	goto aa60;
			}
aa60:
// 89 "scanner.re"
			{
			token->opcode = PHANNOT_T_TRUE;
			return 0;
		}
// 764 "scanner.c"
aa61:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'L':
			case 'l':	goto aa62;
			default:	goto aa44;
			}
aa62:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'S':
			case 's':	goto aa63;
			default:	goto aa44;
			}
aa63:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'E':
			case 'e':	goto aa64;
			default:	goto aa44;
			}
aa64:
			aaaccept = 4;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa43;
			case '\\':	goto aa45;
			default:	goto aa65;
			}
aa65:
// 84 "scanner.re"
			{
			token->opcode = PHANNOT_T_FALSE;
			return 0;
		}
// 865 "scanner.c"
aa66:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'L':
			case 'l':	goto aa67;
			default:	goto aa44;
			}
aa67:
			aaaccept = 1;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case 'L':
			case 'l':	goto aa68;
			default:	goto aa44;
			}
aa68:
			aaaccept = 5;
			aach = *(AAMARKER = ++AACURSOR);
			switch (aach) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'E':
			case 'F':
			case 'G':
			case 'H':
			case 'I':
			case 'J':
			case 'K':
			case 'L':
			case 'M':
			case 'N':
			case 'O':
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
			case 'T':
			case 'U':
			case 'V':
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
			case '_':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case 'e':
			case 'f':
			case 'g':
			case 'h':
			case 'i':
			case 'j':
			case 'k':
			case 'l':
			case 'm':
			case 'n':
			case 'o':
			case 'p':
			case 'q':
			case 'r':
			case 's':
			case 't':
			case 'u':
			case 'v':
			case 'w':
			case 'x':
			case 'y':
			case 'z':	goto aa43;
			case '\\':	goto aa45;
			default:	goto aa69;
			}
aa69:
// 79 "scanner.re"
			{
			token->opcode = PHANNOT_T_NULL;
			return 0;
		}
// 958 "scanner.c"
aa70:
			aach = *++AACURSOR;
			switch (aach) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto aa73;
			default:	goto aa46;
			}
aa71:
			aaaccept = 0;
			AAMARKER = ++AACURSOR;
			aach = *AACURSOR;
aa72:
			switch (aach) {
			case '.':	goto aa70;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto aa71;
			default:	goto aa5;
			}
aa73:
			++AACURSOR;
			aach = *AACURSOR;
			switch (aach) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':	goto aa73;
			default:	goto aa75;
			}
aa75:
// 71 "scanner.re"
			{
			token->opcode = PHANNOT_T_DOUBLE;
			token->value = estrndup(start, AACURSOR - start);
			token->len = AACURSOR - start;
			q = AACURSOR;
			return 0;
		}
// 1018 "scanner.c"
		}
// 183 "scanner.re"


		}
	}

	return status;
}