/*
* Stick Lengths
* I essentially thought I should just get all number to the mean, but the median is the correct answer, actually.
* https://stackoverflow.com/questions/23452479/minimise-the-sum-of-difference-between-each-element-of-an-array-and-an-integer-k
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	long long n, min = 0;

	std::cin >> n;
	std::vector<long long int> v(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		min += std::abs(v[i] - v[n/2]);
	}

	std::cout << min;
}
