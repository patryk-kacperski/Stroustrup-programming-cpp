#include <iostream>
#include <algorithm>

int main() {
	std::cout << "Please enter two numbers: ";
	double val1, val2;
	std::cin >> val1 >> val2;
	std::cout << "Your numbers are val1==" << val1 << ", val2==" << val2 << '\n'
		<< "The larger is: " << std::max(val1, val2) << '\n'
		<< "The smaller is: " << std::min(val1, val2) << '\n'
		<< "The sum is: " << val1 + val2 << '\n'
		<< "The difference is: " << val1 - val2 << '\n'
		<< "The product is: " << val1 * val2 << '\n'
		<< "The ratio is: " << val1 / val2 << '\n';
	return 0;
}