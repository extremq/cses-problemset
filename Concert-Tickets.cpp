/*
	Concert Tickets
	You need a tree that supports searching and sorting but also multiple values. Multiset does this extremely well.
	Similar to USACO's solution.
*/

#include <iostream>
#include <set>

std::multiset<int> tickets;

int main() {
	std::ios_base::sync_with_stdio(false);
	
	int n, m, x;

	std::cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		tickets.insert(x);
	}

	for (int i = 0; i < m; ++i) {
		std::cin >> x;
		auto it = tickets.upper_bound(x);

		if (it == tickets.begin()) {
			std::cout << -1 << '\n';
		}
		else {
			std::cout << *(--it) << '\n';
			tickets.erase(it);
		}
	}
}
