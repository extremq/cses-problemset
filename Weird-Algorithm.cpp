#include <iostream>
 
int main()
{
	long long int n;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	std::cout << n << ' ';
 
	while (n != 1) {
		if (n & 1) {
			n = n * 3 + 1;
		}
		else {
			n >>= 1;
		}
 
		std::cout << n << ' ';
	}
}
