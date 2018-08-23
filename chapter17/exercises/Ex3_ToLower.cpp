#include <iostream>

void toLower(char* s) {
	int i = 0;
	while (*(s + i) != '\0') {
		// std::cout << *(s + i);
		char diff = 'a' - 'A';
		// std::cout << (int)diff;
		if (*(s + i) >= 'A' && *(s + i) <= 'Z') {
			*(s + i) += diff;
			// std::cout << *(s + i);
		}
		++i;
	}
}

int main()
{
	char s[20] = "HelLo WoRld!";
	// std::cout << s;
	toLower(s);
	std::cout << s;
	return 0;
}