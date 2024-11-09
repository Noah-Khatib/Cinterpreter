#include "common.hpp"

enum TokenType {
	// Single-character tokens.
	LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
	COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,
	// One or two character tokens.
	BANG, BANG_EQUAL,
	EQUAL, EQUAL_EQUAL,
	GREATER, GREATER_EQUAL,
	LESS, LESS_EQUAL,
	// Literals.
	IDENTIFIER, STRING, NUMBER,
	// Keywords.
	AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
	PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,
	EndOF
};

class Token {
	TokenType type;
	std::string lexeme;
	std::string literal;
	int line;

public:
	Token(TokenType type, std::string lexeme, std::string literal, int line);
	std::string toString();
	std::string tokenTypeToString(TokenType type);
};