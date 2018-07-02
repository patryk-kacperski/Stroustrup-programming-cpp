/* Sentences will be parsed according to the following grammar:
Sentence:
	Noun Verb
	Sentence Conjunction Sentence
Conjunction:
	"and"
	"or"
	"but"
Noun:
	"birds"
	"fish"
	"C++"
Verb:
	"rules"
	"fly"
	"swim"
*/

#include <iostream>
#include <string>

bool conjunction() {
	std::string s;
	std::cin >> s;
	if (s == "and" || s == "or" || s == "but") {
		return true;
	}
	return false;
}

bool noun() {
	std::string s;
	std::cin >> s;
	if (s == "birds" || s == "fish" || s == "C++") {
		return true;
	}
	return false;
}

bool verb() {
	std::string s;
	std::cin >> s;
	if (s == "rules" || s == "fly" || s == "swim") {
		return true;
	}
	return false;
}

bool senctence() {
	while (true) {
		if (!noun()) {
			return false;
		}
		if (!verb()) {
			return false;
		}
		if (conjunction()) {
			return true;
		}
	}
}

int main() {
	try {
		bool isOk = senctence();
		while (std::cin) {
			if (isOk) {
				std::cout << "OK\n";
			} else {
				std::cout << "Not OK\n";
			}
			isOk = senctence();
		}
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << '\n';
		return 1;
	} catch (...) {
		std::cerr << "Unknown error happened\n";
		return 2;
	}
	return 0;
}
