#include "../header/common.hpp"

void defineAst(std::string baseName, std::vector<std::string> types);
void defineType(std::ofstream& myFile, std::string baseName, std::string className, std::string fieldList);
void defineVisitor(std::ofstream& myFile, std::string baseName, std::vector<std::string> types);

int main(int argc, char *argv[]) {
  std::cout << "hLeoo";

	std::vector<std::string> test = {
		"Binary :Expr left,Token operator,Expr right",
		"Grouping :Expr expression",
		"Literal :std::any value",
		"Unary :Token operator,Expr right" };

		defineAst("Expr", test);
}

void defineAst(std::string baseName, std::vector<std::string> types) {
  std::string lowBaseName = std::string (1, tolower(baseName.at(0))) + baseName.substr(1, baseName.length());
	std::string path = "../" + lowBaseName + ".cpp";

	std::ofstream myFile;
	myFile.open(path);

	myFile << "#include 'common.hpp' \n\n";
	myFile << "class " + baseName + " { \n\n";

	defineVisitor(myFile, baseName, types);

	for (std::string type : types) {
		std::string className = type.substr(0, type.find(":"));
		std::string fields = type.substr(type.find(":") + 1, type.length());
		defineType(myFile, baseName, className, fields);
	}
	myFile << "}";

	myFile.close();
}

void defineVisitor(std::ofstream& myFile, std::string baseName, std::vector<std::string> types) {
	myFile << "class Visitor {\n";
	myFile << "public:\n";

	std::string lowBaseName = std::string (1, tolower(baseName.at(0))) + baseName.substr(1, baseName.length());

	for (std::string type : types) {
		std::string typeName = type.substr(0, type.find(":"));
		myFile << "   virtual void visit (" + typeName + "& " + lowBaseName + ") = 0;\n";
	}

	myFile << "}\n\n";
}

void defineType(std::ofstream& myFile, std::string baseName, std::string className, std::string fieldList) {
		std::vector<std::string> fields;
		std::string token;
		std::stringstream filedListStream(fieldList);

		myFile << "class " + className + "{\n";
		myFile << "  " + className + "(" + fieldList + ") {\n";

		while (std::getline(filedListStream, token, ',')) fields.push_back(token);

		for (std::string field : fields) {
			myFile << "    " + field + " =" +
				field.substr(field.find(' '), field.length()) + "; \n";
		}
		myFile << "  }\n";

		myFile << "  void accept(Visitor& visitor) override {	visitor.visit(*this) }\n";
		myFile << "}\n";
}