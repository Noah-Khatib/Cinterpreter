#include "header/common.hpp"
#include "header/lox.hpp"

  template <typename... Args>
  void parenthesize( Args... args){
		std::cout << "Test";
    //std::cout << args;
  }

int main(int argc, char* argv[]) {

  parenthesize("Hello", 12, true,  "test");

	// Lox lox;

	// if (argc > 2) {
	// 	std::cout << "Usage: jlox [script]";
	// }
	// else if (argc == 2) {
	// 	lox.runFile(argv[1]);
	// }
	// else {
	// 	lox.runPrompt();
	// }

	return 0;
}

