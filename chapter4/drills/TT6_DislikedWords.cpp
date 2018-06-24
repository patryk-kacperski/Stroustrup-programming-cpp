#include <iostream>

int main() {
	const std::string dislikedWord1 = "javascript";
	const std::string dislikedWord2 = "spider";
	const std::string dislikedWord3 = "work";

	for (std::string current; std::cin >> current;) {
		if (current == dislikedWord1 || current == dislikedWord2 || current == dislikedWord3) {
			std::cout << "BLEEP\n";
		} else {
			std::cout << current << '\n';
		}
	}

	return 0;
}