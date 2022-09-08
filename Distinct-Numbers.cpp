/*
	Distinct Numbers
	Because the range of number is too big for using hash tables, we can resort to two things:
	1. Sorting the array then counting the distincts in a linear way (could use heapsort for sorting while reading the numbers);
	2. Building a balanced binary tree and counting the nodes. I used this method as it's more straightforward.

	Both should be around O(n log n). The second method uses less space on average but has the same upper bound on space as the first one.
*/

#include <iostream>
#include <set>

int main() {
	std::ios_base::sync_with_stdio(false);
	
	std::set<int> distincts;

	int n, x;
	std::cin >> n;
	
	while (n--) {
		std::cin >> x;
		distincts.insert(x);
	}

	std::cout << distincts.size() << '\n';
}
