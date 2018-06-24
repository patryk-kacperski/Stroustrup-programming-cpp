#include <iostream>

int main() {
	constexpr int rice1 {1000}, rice2 {1000000}, rice3 {1000000000};
	bool rice1Printed = false, rice2Printed = false;
	int grainsRecieved = 0;
	int grainsForCurrentSquare = 2;
	int numberOfSquaresCovered = 0;
	while (grainsRecieved < rice3) {
		if (grainsRecieved > rice1 && !rice1Printed) {
			std::cout << "You need " << numberOfSquaresCovered << " squares to get at least " << rice1 << " grains of rice\n";
			rice1Printed = true;  
		}
		if (grainsRecieved > rice2 && !rice2Printed) {
			std::cout << "You need " << numberOfSquaresCovered << " squares to get at least " << rice2 << " grains of rice\n";
			rice2Printed = true;
		}
		grainsRecieved += grainsForCurrentSquare;
		grainsForCurrentSquare *= 2;
		++numberOfSquaresCovered;
	}
	std::cout << "You need " << numberOfSquaresCovered << " squares to get at least " << rice3 << " grains of rice\n";
	return 0;
}