#include <iostream>
#include <cmath>

int main() {
	// checking sizes of varibles
	std::cout << "Size of char is: " << sizeof(char) << " bytes\n";
	std::cout << "Size of short is: " << sizeof(short) << " bytes\n";
	std::cout << "Size of int is: " << sizeof(int) << " bytes\n";
	std::cout << "Size of long is: " << sizeof(long) << " bytes\n";
	std::cout << "Size of float is: " << sizeof(float) << " bytes\n";
	std::cout << "Size of double is: " << sizeof(double) << " bytes\n";
	std::cout << "Size of int pointer is: " << sizeof(int*) << " bytes\n";
	std::cout << "Size of double pointer is: " << sizeof(double*) << " bytes\n";

	// square root
	std::cout << "\nCalculating square roots:\n";
	int n;
	while (std::cin >> n) {
		int res = sqrt(n);
		if (errno == EDOM) {
			std::cout << "no square root\n";
			errno = 0;
		} else {
			std::cout << res << '\n';	
		}
	}
	return 0;
}