/*
This problem simply asks us to compute 2 ^ n mod (10 ^ 9 + 7)
*/
#include <iostream>
 
int main()
{
	long long int n;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	long long int power = 1;
 
	for (long long int i = 0; i < n; ++i) {
		power *= 2;
		power %= 1000000007;
	}
 
	std::cout << power;
}
