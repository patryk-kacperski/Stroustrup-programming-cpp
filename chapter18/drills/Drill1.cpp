#include <iostream>
#include <algorithm>

int ga[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int arr[], int n) {
	int la[10];
	std::copy(ga, ga + 10, la);
	for (int i = 0; i < 10; ++i) { std::cout << la[i] << ' '; }
	std::cout << '\n';
	int* p = new int[n];
	std::copy(arr, arr + n, p);
	for (int i = 0; i < n; ++i) { std::cout << p[i] << ' '; }
	std::cout << '\n';
	delete[] p;
}

int main() {
	f(ga, 10);
	int aa[] = {1, 2, 6, 24, 120, 720, 720*7, 720*8*7, 720*8*9*7, 720*7*8*9*10};
	f(aa, 10);
	return 0;
}