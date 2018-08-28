#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main() {
	std::list<int> li {0, 7, 2, 5, 6, 3, 8, 10, 1, 12};
	std::vector<double> vd(10); 
	std::copy(li.begin(), li.end(), vd.begin());
	std::sort(vd.begin(), vd.end());
	for (double d : vd) std::cout << d << ' ';
	std::cout << '\n';
	return 0;
}