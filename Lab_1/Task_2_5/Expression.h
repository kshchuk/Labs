#pragma once

#include <iostream>
#include<vector>
#include<stack>

#include "BinaryTree.h"


class Expression : public BinaryTree<std::string>
{
public:
	Expression(std::string);
	void PrintVarList();
	void Simplify(Node* node = nullptr, Node* parent = nullptr);
	Node* Differentiate(std::string var, Node* node = nullptr);
	double CalculateExpression(std::map<std::string, double> values_of_variables);

private:
	Expression(Node*);

	const std::map<std::string, int> kFunctionsPriorities =
	{ {"sin", 1}, {"cos", 1}, {"tg", 1}, {"log", 2}, {"ln", 1}, {"^", 3},
		{"*", 4}, {"/", 4}, {"+", 5}, {"-", 5}, {"(", 6} };
	std::vector<std::string> vars;

	void ProcessOperation(std::string operation, std::stack<std::string>& operators, 
		std::vector<std::string>& rpn); // rpn - reverse polish notation
	std::vector<std::string> GenRpn(std::string expression);
	void GenSubTree(Node** root, std::vector<std::string>::iterator& start);
	void ConvertVarsToNumbers(std::map<std::string, double> values, Node* node);
	void SimplifyBinaryFunction(Node* node = nullptr, Node* parent = nullptr);
	void SimplifyUnaryFunction(Node* node = nullptr, Node* parent = nullptr);
	bool isNumber(std::string str);
	bool isFunction(std::string str);
	bool isUnaryFunction(std::string str);
	void CheckVar(std::string var);
	double CalculateFunction(std::string function, double arg_1, double arg_2 = NULL);
	bool Compare(Node* root_1, Node* root_2);

	void dSin(std::string var, Node*& sin_node);
	void dCos(std::string var, Node*& cos_node);
	void dTg(std::string var, Node*& tg_node);
	void dLn(std::string var, Node*& ln_node);
	void dLog(std::string var, Node*& log_node);
	void dPow(std::string var, Node*& pow_node);
	void dMult(std::string var, Node*& mult_node);
	void dDiv(std::string var, Node*& div_node);
};

#include "Expression.ipp"