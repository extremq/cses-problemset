/*
The n'th gray code can be obtained by xoring the n'th binary number with itself but rightshifted once.
For example, the gray code for 3 is 11 ^ (11 >> 1) = 11 ^ 01 = 10
*/
#include <iostream>
 
int main()
{
	long long int n;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	long long int upperBound = 1LL << n, x;
	for (long long i = 0; i < upperBound; ++i) {
		x = i ^ (i >> 1);
		
		for (long long j = n - 1; j >= 0; --j) {
			std::cout << !!(x & (1LL << j));
		}
 
		std::cout << '\n';
	}
}
