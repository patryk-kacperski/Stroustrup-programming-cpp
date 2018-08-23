#include <iostream>

int main() {
	int i = 0;
	try {
		while (true) {
			int* a = new int[1000000];
			++i;
			std::cout << "Allocated " << 1 * i << " MB of memory\n";
		}
	} catch (std::bad_alloc e) {
		while(true) {}
	}
}