#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <fstream>

struct Item {
	std::string name;
	int iid;
	double value;
};

std::istream& operator>>(std::istream& in, Item& item) {
	in >> item.name >> item.iid >> item.value;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
	out << "Name: " << item.name << ", id: " << item.iid << ", value: " << item.value;
	return out;
}

void print(const std::list<Item>& vi) {
	for (Item item: vi) {
		std::cout << item << '\n';
	}
}

std::list<Item> readFromFile() {
	std::ifstream fin {"data.txt"};
	std::list<Item> res;
	Item item;
	while (fin >> item) {
		res.push_back(item);
	}
	return res;
}

template<typename T>
void sort(std::list<Item>& vi, T pred) {
	vi.sort(pred);
}

void removeFromList(std::list<Item>& vi, std::list<Item>::iterator item) {
	if (item != vi.end()) {
		vi.erase(item);
	}
}

void removeByName(std::list<Item>& vi, const std::string name) {
	auto itemToRemove = std::find_if(vi.begin(), vi.end(), [&](const Item& item) { return item.name == name; });
	removeFromList(vi, itemToRemove);
}

void removeById(std::list<Item>& vi, int iid) {
	auto itemToRemove = std::find_if(vi.begin(), vi.end(), [&](const Item& item) { return item.iid == iid; });
	removeFromList(vi, itemToRemove);
}

int main() {
	std::list<Item> vi = readFromFile();
	sort(vi, [](const Item& lhs, const Item& rhs) { return lhs.name < rhs.name; });
	sort(vi, [](const Item& lhs, const Item& rhs) { return lhs.iid < rhs.iid; });
	sort(vi, [](const Item& lhs, const Item& rhs) { return lhs.value >= rhs.value; });
	vi.push_back({"horse_shoe", 9, 12.34});
	vi.push_back({"Canon S400", 9988, 499.95});
	removeByName(vi, "test4");
	removeByName(vi, "test7");
	removeById(vi, 6);
	removeById(vi, 5);
	print(vi);
	return 0;
}