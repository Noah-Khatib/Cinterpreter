#include "header/lox.hpp"
#include "header/token.hpp"
#include "header/scanner.hpp"

#include <stdio.h>

void Lox::runFile(char* fileName) {
	std::fstream file(fileName);

	if (!file.is_open()) {
		std::cerr << "Error" << "\n";
		exit(1);
	}

	std::stringstream buffer;
	buffer << file.rdbuf();

	file.close();

	run(buffer.str());
	if (hadError) { exit(1); }
}


void Lox::runPrompt() {

	std::string line;

	for (;;) {
		std::cout << ">";
		std::getline(std::cin, line);
		if (line == "exit") {
			break;
		}
		run(line);
		if (hadError) hadError = false;
		}
}


void Lox::run(std::string source) {
	Scanner scanner(source);
	std::vector<Token> tokenList = scanner.scanTokens();

	for (Token token : tokenList) {
		std::cout << token.toString();
	}
}

void Lox::error(int line, std::string where, std::string message) {
	std::cerr << "[line " << line << "] Error" << where << ": " << message << "\n";
	hadError = true;
}