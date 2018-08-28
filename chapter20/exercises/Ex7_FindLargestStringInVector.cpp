#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
	std::vector<std::string> v {"a", "fdf", "lalla", "wowowowowo", "terererer", "zazaza", "xoxoxooxxoox", "ppupupuspaup"};
	std::string largest = "";
	for(const std::string& s: v) {
		largest = std::max(largest, s);
	}
	std::cout << "Largest string in vector is: " << largest << '\n';
	return 0;
}