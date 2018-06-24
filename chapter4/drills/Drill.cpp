#include <iostream>
#include <algorithm>
#include <vector>

double abs(double a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

double getValueInCm(double val, std::string unit) {
	constexpr double mToCm = 100.0;
	constexpr double inToCm = 2.54;
	constexpr double ftToCm = 12 * inToCm;

	if (unit == "m") {
		return val * mToCm;
	} else if (unit == "in") {
		return val * inToCm;
	} else if (unit == "ft") {
		return val * ftToCm;
	}
	return val;
}

bool isUnitLegal(std::string unit) {
	return unit == "m" || unit == "in" || unit == "ft" || unit == "cm";
}

int main() {
	double smallest{0}, largest{0}, current{0}, sum{0};
	std::string unit;
	std::vector<double> values;
	std::cin >> current >> unit;
	double currentCm = getValueInCm(current, unit);
	smallest = currentCm;
	largest = currentCm;
	sum += currentCm / 100;
	std::cout << current << unit << "\nthe largest so far\nthe smallest so far\n";
	while (std::cin >> current >> unit) {
		if (!isUnitLegal(unit)) {
			std::cout << "Illegal unit!\n";
			continue;
		}
		currentCm = getValueInCm(current, unit);
		std::cout << current << unit << '\n';
		if (currentCm > largest) {
			largest = currentCm;
			std::cout << "the largest so far\n";
		}
		if (currentCm < smallest) {
			smallest = currentCm;
			std::cout << "the smallest so far\n";
		}
		double currentM = currentCm / 100;
		sum += currentM;
		values.push_back(currentM);
	}
	std::cout << "The smallest value: " << smallest / 100 << "m\n"
		<< "The largest value: " << largest / 100 << "m\n"
		<< "The sum of entered values: " << sum << "m\n"
		<< "Number of entered values: " << values.size() << '\n'
		<< "Sorted values:\n";
	std::sort(values.begin(), values.end());
	for (double value : values) {
		std::cout << value << "m\n";
	}
	return 0;
}