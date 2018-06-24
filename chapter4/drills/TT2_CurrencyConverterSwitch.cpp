#include <iostream>

int main() {
	constexpr double yenToDollar = 0.009;
	constexpr double kronerToDollar = 0.124;
	constexpr double poundToDollar = 1.326;

	std::cout << "Enter amount of money and currency sign (y - yen, k - kroner, p - pound) to be converted to dollars: ";
	double amount {0};
	char currency {' '};
	std::cin >> amount >> currency;

	switch (currency) {
		case 'y':
			std::cout << amount << " yen == " << amount * yenToDollar << "$\n";
			break;
		case 'k':
			std::cout << amount << " kroner == " << amount * kronerToDollar << "$\n";
			break;
		case 'p':
			std::cout << amount << " pounds == " << amount * poundToDollar << "$\n";
			break;
		default:
			std::cout << "Unknown currency\n";
	}

	return 0;
}