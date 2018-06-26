#include <iostream>

int main() {
	std::cout << "Please enter expression (we can handle +, -, *, /)\n";
	std::cout << "add an x to end expression (e.g., 1+2*3x): ";
	int lval = 0;
	int rval;
	std::cin >> lval;
	if (!std::cin) {
		std::cerr << "no first operand\n";
		return 1;
	}

	for (char op; std::cin >> op;) {
		if (op != 'x') {
			std::cin >> rval;
		}
		if (!std::cin) {
			std::cerr << "no second operand\n";
			return 1;
		}
		switch (op) {
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		default:
			std::cout << "Result: " << lval << '\n';
			return 0;
		}
		
	}
	std::cerr << "bad expression\n";
	return 1;
}