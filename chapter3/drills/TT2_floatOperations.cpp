#include <iostream>
#include <math.h>

int main()
{
	std::cout << "Please enter a floating-point value: ";
	int n;
	std::cin >> n;
	std::cout << "n == " << n
		<< "\nn+1 == " << n + 1
		<< "\nthree times n == " << 3 * n
		<< "\ntwice n == " << n + n
		<< "\nn squared == " << n * n
		<< "\nhalf of n == " << n / 2
		<< "\nsqare root of n == " << sqrt(n)
		<< "\n";
	return 0;
}