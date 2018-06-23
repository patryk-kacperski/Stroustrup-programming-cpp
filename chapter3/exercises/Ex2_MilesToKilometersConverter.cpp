#include <iostream>

int main() {
	std::cout << "Miles to kilometers converter.\nPlease enter miles: ";
	double miles;
	std::cin >> miles;
	std::cout << miles << " miles are equal to " << miles * 1.609 << " kilometers.\n";
	return 0;
}