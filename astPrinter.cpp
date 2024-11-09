// #include "Expr.cpp"
// #include "header/common.hpp"

// class AstPrinter {
//   std::string print

// public: 
//   std::string visitBinaryExpr(Expr.Binary expr) const override {
//     return parenthesize(expr.operator.lexeme, expr.left, expr.right);
//   }

//   std::string visitGroupingExpr(Expr.Grouping expr)const override {
//     return parenthesize("group", expr.expression);
//   }

//   std::string visitLiteralExpr(Expr.Literal expr) {
//     if (expr.value == null) return "nil";
//     return expr.value.toString();
//   }

//   std::string visitUnaryExpr(Expr.Unary expr) {
//     return parenthesize(expr.operator.lexeme, expr.right);
//   }

//   template <class... Expr>
//   std::string parenthesize( std::string name, Expr... exprs){
//     std::cout << exprs;
//   }

// }