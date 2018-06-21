#include <iostream>

int main() {
	std::cout << "Please enter your first name and age\n";
	std::string firstName;
	double age;
	std::cin >> firstName >> age;
	double ageInMonths = age * 12;
	std::cout << "Hello, " << firstName << " (age " << ageInMonths << " months)\n";
	return 0;
}