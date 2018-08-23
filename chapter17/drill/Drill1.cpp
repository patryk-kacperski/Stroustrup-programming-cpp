#include <iostream>

constexpr int arraySize = 10;
constexpr int arraySize2 = 11;
constexpr int arraySize3 = 20;

void printArray10(std::ostream& os, int* a) {
	for (int i = 0; i < arraySize; ++i) {
		os << a[i] << ' ';
	}
	os << '\n';
}

void printArray11(std::ostream& os, int* a) {
	for (int i = 0; i < arraySize2; ++i) {
		os << a[i] << ' ';
	}
	os << '\n';
}

void printArray(std::ostream& os, int* a, int n) {
	for (int i = 0; i < n; ++i) {
		os << a[i] << ' ';
	}
	os << '\n';
}

int main() {
	int* numbers = new int[arraySize] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printArray10(std::cout, numbers);
	delete [] numbers;
	int* hundrets = new int[arraySize] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	printArray10(std::cout, hundrets);
	delete [] hundrets;
	int* hundrets2 = new int[arraySize2] {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	printArray11(std::cout, hundrets2);
	delete [] hundrets2;
	int* numbers2 = new int[arraySize3];
	printArray(std::cout, numbers2, arraySize3);
	delete [] numbers2;
	return 0;
}