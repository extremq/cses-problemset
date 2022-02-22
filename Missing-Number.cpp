/*
The sum from all the numbers from 1 to n is n * (n + 1) / 2, the Gauss sum.
We only have one missing number, that means we can determine the missing number at read-time by subtracting all the other ones.
*/
#include <iostream>

int main()
{
	long long int n, x, sum;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	sum = n * (n + 1) / 2;
	
	n--; 
	while (n--) {
		std::cin >> x;
		sum -= x;
	}
 
	std::cout << sum << '\n';
}
