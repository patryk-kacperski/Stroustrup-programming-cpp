#include <iostream>
#include <vector>

std::vector<int> gv {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(std::vector<int> v) {
	std::vector<int> lv(v.size());
	lv = gv;
	for (int n : lv) { std::cout << n << ' '; }
	std::cout << '\n';
	std::vector<int> lv2 = v;
	for (int n : lv2) { std::cout << n << ' '; }
	std::cout << '\n';
}

int main() {
	f(gv);
	std::vector<int> vv {1, 2, 6, 24, 120, 720, 720*7, 720*8*7, 720*8*9*7, 720*7*8*9*10};
	f(vv);
	return 0;
}