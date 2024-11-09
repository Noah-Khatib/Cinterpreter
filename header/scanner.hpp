#include "common.hpp"

class Scanner {
	std::string source;
	std::vector<Token> tokenList;
	int start = 0;
	int current = 0;
	int line = 1;
	std::map<std::string, TokenType> keywords;

public:
	Scanner(std::string source);
	std::vector<Token> scanTokens();
	void scanToken();
	void addToken(TokenType type);
	void addToken(TokenType type, std::string literal);
	bool match(char expected);
	bool isAtEnd();
	char peek();
	char peekNext();
	char advance();
	void string();
	void number();
	void identifier();
};

