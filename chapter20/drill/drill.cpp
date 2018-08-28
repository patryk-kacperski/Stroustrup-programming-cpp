#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<typename Iter1, typename Iter2>
Iter2 myCopy(Iter1 f1, Iter1 e1, Iter2 f2) {
	while (f1 != e1) {
		*(f2++) = *(f1++);
	}
	return f2;
}

int main() {
	int arr[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> vi {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::list<int> li {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int arr2[10];
	std::copy(arr, arr + 10, arr2);
	std::vector<int> vi2 = vi;
	std::list<int> li2 = li;

	for (int i = 0; i < 10; ++i) { arr[i] += 2; }
	for (int& n : vi) { n += 3; }
	for (int& n : li) { n += 5; }

	std::vector<int> vi3(10);
	myCopy(arr + 0, arr + 10, vi3.begin());
	int arr3[10];
	myCopy(li.begin(), li.end(), arr3);

	auto pos = std::find(vi.begin(), vi.end(), 3);
	if (pos == vi.end()) {
		std::cout << "Not found\n";
	} else {
		std::cout << "Found at position: " << pos - vi.begin() << '\n';
	}
	auto pos2 = std::find(li.begin(), li.end(), 27);
	if (pos2 == li.end()) {
		std::cout << "Not found\n";
	} else {
		int counter {0};
		for (auto it = li.begin(); it != pos2; ++it) { ++counter; }
		std::cout << "Found at position: " << counter << '\n';
	}

	for (int i = 0; i < 10; ++i) { std::cout << arr[i] << ' '; }
	std::cout << '\n';
	for (int& n : vi) { std::cout << n << ' '; }
	std::cout << '\n';
	for (int& n : li) { std::cout << n << ' '; }
	std::cout << '\n';
	for (int i = 0; i < 10; ++i) { std::cout << arr2[i] << ' '; }
	std::cout << '\n';
	for (int& n : vi2) { std::cout << n << ' '; }
	std::cout << '\n';
	for (int& n : li2) { std::cout << n << ' '; }
	std::cout << '\n';
	for (int i = 0; i < 10; ++i) { std::cout << arr3[i] << ' '; }
	std::cout << '\n';
	for (int& n : vi3) { std::cout << n << ' '; }
	std::cout << '\n';

	return 0;
}