#include <iostream>

int square(int n) {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		res += n;
	}
	return res;
}

int main() {
	for (int i = 0; i < 100; ++i) {
		std::cout << i << '\t' << square(i) << '\n';
	}
	return 0;
}