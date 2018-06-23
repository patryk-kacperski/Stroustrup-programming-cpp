#include <iostream>

int main() {
	constexpr double yenToDollar = 0.009;
	constexpr double kronerToDollar = 0.124;
	constexpr double poundToDollar = 1.326;

	std::cout << "Enter amount of money and currency sign (y - yen, k - kroner, p - pound) to be converted to dollars: ";
	double amount {0};
	char currency {' '};
	std::cin >> amount >> currency;

	if (currency == 'y') {
		std::cout << amount << " yen == " << amount * yenToDollar << "$\n";
	} else if (currency == 'k') {
		std::cout << amount << " kroner == " << amount * kronerToDollar << "$\n";
	} else if (currency == 'p') {
		std::cout << amount << " pounds == " << amount * poundToDollar << "$\n";
	} else {
		std::cout << "Unknown currency\n";
	}

	return 0;
}