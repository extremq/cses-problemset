/*
If n is even, then split the numbers in two groups:
1 2 3 4 5 6 7 8 becomes
1 5 2 6 3 7 4 8 by adding half of n.

Otherwise, first print the middle number then create the pairs:
1 2 3 4 5 6 7 becomes
4 1 5 2 6 3 7, basically reducing the problem to the first case (even amount of terms).

*/
#include <iostream>
 
int main()
{
	int n;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	if (n < 4 && n > 1) {
		std::cout << "NO SOLUTION\n";
 
		return 0;
	}
 
	if (n & 1) {
		std::cout << n / 2 + 1 << ' ';
 
		for (int i = 1; i < n / 2 + 1; ++i) {
			std::cout << i << ' ' << n - i + 1 << ' ';
		}
	}
	else {
		for (int i = n / 2; i >= 1; --i) {
			std::cout << i << ' ' << i + n / 2 << ' ';
		}
	}
}
