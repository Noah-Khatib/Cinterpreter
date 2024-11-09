#include "header/lox.hpp"
#include "header/token.hpp"
#include "header/scanner.hpp"

Scanner::Scanner(std::string source) : source(source) {
	keywords.insert({{"and", AND}, {"class", CLASS}, {"else", ELSE}, {"false", FALSE}, {"for", FOR},
		{"fun", FUN}, {"nil", NIL}, { "or", OR }, { "print", PRINT }, { "return", RETURN },
		{ "super", SUPER }, { "this", THIS }, { "true", TRUE }, { "var", VAR }, { "while", WHILE }});

}

std::vector<Token> Scanner::scanTokens() {

		while (current < source.size()) {
			start = current;
			scanToken();
		}
		tokenList.push_back({ EndOF, "", "NULL", line });
		return tokenList;
}

void Scanner::scanToken() {
	char c = advance();
		switch (c) {
			case '(': addToken(LEFT_PAREN);	break;
			case ')': addToken(RIGHT_PAREN); break;
			case '{': addToken(LEFT_BRACE); break;
			case '}': addToken(RIGHT_BRACE); break;
			case ',': addToken(COMMA); break;
			case '.': addToken(DOT); break;
			case '-': addToken(MINUS); break;
			case '+': addToken(PLUS); break;
			case ';': addToken(SEMICOLON); break;
			case '*': addToken(STAR); break;
			case '!': addToken(match('=') ? BANG_EQUAL : BANG); break;
			case '=': addToken(match('=') ? EQUAL_EQUAL : EQUAL);	break;
			case '<':	addToken(match('=') ? LESS_EQUAL : LESS); break;
			case '>': addToken(match('=') ? GREATER_EQUAL : GREATER); break;
			case '/': {
				if (peek() == '*') { 
					while (!isAtEnd()) {
						if (peek() == '\n') line++;
						if (peek() == '*' && peekNext() == '/') { 
							advance(); 
							advance(); 
							break; 
						}
						advance(); 
					}
				}
				else if (peek() == '/') {
					while (peek() != '\n' && !isAtEnd()) {
						advance();
					}
				}
				else {
					addToken(SLASH);
				}
			}break;
			case ' ': break;
			case '\r': break;
			case '\t': break;
			case '\n': line++; break;

			case '"': string(); break;

			default: {
				if (isdigit(c)) {
					number();
				}
				else if (isalpha(c)) {
					identifier();
				}
				else
				{
					Lox lox;
					lox.error(line, "", "unexpected character!");
				}
			}break;
		}
}


void Scanner::identifier() {
	while (isalnum(peek())) advance();

	TokenType type;
	std::string text = source.substr(start, current - start);

	if (keywords.find(text) != keywords.end()) type = keywords[text];
	else type = IDENTIFIER;

	addToken(type);
}

void Scanner::string() {
	while (peek() != '"' && !isAtEnd()) {
		if (peek() == '\n') line++;
		advance();
	}
	if (isAtEnd()) {
		Lox lox;
		lox.error(line, "", "Unterrminated String!");
	}
	advance();

	std::string value = source.substr(start, current - start);
	addToken(STRING, value);
}

void Scanner::number() {
	while (isdigit(peek())) advance();

	if (peek() == '.' && isdigit(peekNext())) {
		advance();

		while (isdigit(peek())) advance();
	}

	addToken(NUMBER, (source.substr(start, current - start)));

}

void Scanner::addToken(TokenType type){
	addToken(type, "NULL");
}

void Scanner::addToken(TokenType type, std::string literal) {
		std::string text = source.substr(start, current - start);
		tokenList.push_back({ type, text, literal, line });
}

bool Scanner::match(char expected) {
	if (isAtEnd()) return false;
	char test = source.at(current++);
	if (test != expected) { return false; }
	return true;
}

bool Scanner::isAtEnd() {
	return current >= source.size();
}

char Scanner::peek() {
	if (isAtEnd()) return '\0';
	return source.at(current);
}

char Scanner::peekNext() {
	if (current + 1 >= source.size()) return '\0';
	return source.at(current + 1);
}

char Scanner::advance() {
	return source.at(current++);
}