#include "common.hpp"

class Lox {
	bool hadError;
public:
	void runFile(char* fileName);
	void runPrompt();
	void run(std::string source);
	void error(int line, std::string where, std::string message);
};