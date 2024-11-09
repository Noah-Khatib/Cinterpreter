#include "header/token.hpp"

Token::Token(TokenType type,	std::string lexeme, std::string literal,	int line)
	: type(type), lexeme(lexeme), literal(literal), line(line) {}

std::string Token::toString(){
	return tokenTypeToString(type) + " " + lexeme + " " + literal + " " + std::to_string(line) + "\n";
}

std::string Token::tokenTypeToString(TokenType type) {
  switch (type) {
  case LEFT_PAREN: return "LEFT_PAREN"; break;
  case RIGHT_PAREN: return "RIGHT_PAREN"; break;
  case LEFT_BRACE: return "LEFT_BRACE"; break;
  case RIGHT_BRACE: return "RIGHT_BRACE"; break;
  case COMMA: return "COMMA"; break;
  case DOT: return "DOT"; break;
  case MINUS: return "MINUS"; break;
  case PLUS: return "PLUS"; break;
  case SEMICOLON: return "SEMICOLON"; break;
  case SLASH: return "SLASH"; break;
  case STAR: return "STAR"; break;
  case BANG: return "BANG"; break;
  case BANG_EQUAL: return "BANG_EQUAL"; break;
  case EQUAL: return "EQUAL"; break;
  case EQUAL_EQUAL: return "EQUAL_EQUAL"; break;
  case GREATER: return "GREATER"; break;
  case GREATER_EQUAL: return "GREATER_EQUAL"; break;
  case LESS: return "LESS"; break;
  case LESS_EQUAL: return "LESS_EQUAL"; break;
  case IDENTIFIER: return "IDENTIFIER"; break;
  case STRING: return "STRING"; break;
  case NUMBER: return "NUMBER"; break;
  case AND: return "AND"; break; 
  case CLASS: return "CLASS"; break; 
  case ELSE: return "ELSE"; break;
  case FALSE: return "FALSE"; break;
  case FUN: return "FUN"; break;
  case FOR: return "FOR"; break;
  case IF: return "IF"; break;
  case NIL: return "NIL"; break;
  case OR: return "OR"; break;
  case PRINT: return "PRINT"; break;
  case RETURN: return "RETURN"; break;
  case SUPER: return "SUPER"; break;
  case THIS: return "THIS"; break;
  case TRUE: return "TRUE"; break;
  case VAR: return "VAR"; break;
  case WHILE: return "WHILE"; break;
  case EndOF: return "EndOF"; break;
  default: return "UNKNOWN_TOKEN";
  }
}