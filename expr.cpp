#include 'common.hpp' 

class Expr { 

class Visitor {
public:
   virtual void visit (Binary & expr) = 0;
   virtual void visit (Grouping & expr) = 0;
   virtual void visit (Literal & expr) = 0;
   virtual void visit (Unary & expr) = 0;
}

class Binary {
  Binary (Expr left,Token operator,Expr right) {
    Expr left = left; 
    Token operator = operator; 
    Expr right = right; 
  }
  void accept(Visitor& visitor) override {	visitor.visit(*this) }
}
class Grouping {
  Grouping (Expr expression) {
    Expr expression = expression; 
  }
  void accept(Visitor& visitor) override {	visitor.visit(*this) }
}
class Literal {
  Literal (std::any value) {
    std::any value = value; 
  }
  void accept(Visitor& visitor) override {	visitor.visit(*this) }
}
class Unary {
  Unary (Token operator,Expr right) {
    Token operator = operator; 
    Expr right = right; 
  }
  void accept(Visitor& visitor) override {	visitor.visit(*this) }
}
}