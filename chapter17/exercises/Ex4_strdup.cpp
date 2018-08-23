#include <iostream>

char* strdup(const char* s) {
	int count {0};
	while(s[count] != '\0') { ++count; }
	++count; // space for string terminator
	char* dup = new char[count];
	for (int i = 0; i < count; ++i) {
		dup[i] = s[i];
	}
	return dup;
}

int main() {
	char s[] = "Test";
	char* dup = strdup(s);
	std::cout << dup << '\n';
	return 0;
}