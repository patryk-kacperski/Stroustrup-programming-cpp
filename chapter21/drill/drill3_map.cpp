#include <iostream>
#include <map>
#include <algorithm>
#include <string>

template<typename Key, typename Value>
void print(const std::map<Key, Value>& m) {
	for (auto record: m) {
		std::cout << record.first << ": " << record.second << '\n';
	}
}

void insertInitialValues(std::map<std::string, int>& m) {
	m["test1"] = 7;
	m["test2"] = -17;
	m["test3"] = 13;
	m["test4"] = 42;
	m["test5"] = -53;
	m["test6"] = 53;
	m["test7"] = -16;
	m["test8"] = 72;
	m["test9"] = 47;
	m["test10"] = 52;
}

void removeKey(std::map<std::string, int>& m, std::string key) {
	m.erase(key);
}

void readFromInput(std::map<std::string, int>& m, std::istream& in) {
	std::string key;
	int value;
	while (in >> key >> value) {
		m[key] = value;
	}
}

int sum(const std::map<std::string, int>& m) {
	int sum {0};
	for (auto record: m) {
		sum += record.second;
	}
	return sum;
}

void copy(const std::map<std::string, int>& source, std::map<int, std::string>& dest) {
	for (auto record: source) {
		dest[record.second] = record.first;
	}
}

int main() {
	std::map<std::string, int> msi;
	insertInitialValues(msi);
	removeKey(msi, "test5");
	// readFromInput(msi, std::cin);
	print(msi);
	std::cout << "sum of elements: " << sum(msi) << '\n';

	std::map<int, std::string> mis;
	copy(msi, mis);
	print(mis);
	return 0;
}