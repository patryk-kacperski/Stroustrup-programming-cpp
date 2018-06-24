#include <iostream>
#include <vector>

int main() {
	constexpr int max = 100;
	std::vector<bool> isComposite(max);
	std::vector<int> primes;
	for (int i = 2; i < max; ++i)
	{
		if (!isComposite[i]) {
			primes.push_back(i);
			for (int j = i * i; j < max; j += i) {
				isComposite[j] = true;
			}
		}
	}
	for (int n : primes) {
		std::cout << n << ' ';
	}
	std::cout << '\n';
	return 0;
}