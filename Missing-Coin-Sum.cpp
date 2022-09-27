/*
* Missing Coin Sum
* If the first coin isn't a 1, then 1 is the answer.
* Otherwise, a good explanation is provided here https://www.geeksforgeeks.org/find-smallest-value-represented-sum-subset-given-array/
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

	if (v[0] > 1) {
		std::cout << 1 << '\n';
		return 0;
	}

	long long sum = v[0];
	for (int i = 1; i < n; ++i) {
		if (sum < v[i] - 1) {
			std::cout << sum + 1;
			return 0;
		}
		sum += v[i];
	}
	
	std::cout << sum + 1;

}
