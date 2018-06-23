#include <iostream>

int main() {
	std::cout << "Please enter operation sign (+, -, *, /) followed by two numbers: ";
	std::string operation;
	double op1, op2;
	std::cin >> operation >> op1 >> op2;
	std::cout << op1 << ' ' << operation << ' ' << op2 << " = ";
	if (operation == "+") {
		std::cout << op1 + op2;
	} 
	if (operation == "-") {
		std::cout << op1 - op2;
	}
	if (operation == "*") {
		std::cout << op1 * op2;
	}
	if (operation == "/") {
		std::cout << op1 / op2;
	}
	std::cout << '\n';
	return 0;
}