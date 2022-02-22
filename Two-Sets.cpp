/*
The sum of all the terms must be divisible by two, we can use the Gauss sum to arrive at a conclusion.
If it's valid, then we can do pairings:
Odd n
1 2 3 4 5 6 7
7 and 1 + 6 are paired (always start with n and n - 1 + 1)
then
2 5 and 3 4 are paired. We are guaranteed to have an even number of pairs since having an even sum means
having an even amount of odd terms. 
Even n
1 2 3 4 5 6 7 8
1 8 and 2 7
3 6 and 4 5
Guaranteed to be possible since we have an even amount of odd terms.
*/
#include <iostream>
 
int main()
{
	long long int n;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	if ((n * (n + 1) / 2) % 2) {
		std::cout << "NO\n";
 
		return 0;
	}
	
	std::cout << "YES\n";
 
	if (n % 2) {
		std::cout << n / 2 << '\n';
		std::cout << n << ' ';
 
		for (long long int i = 2; i < n / 2; i += 2) {
			std::cout << i << ' ' << n - i << ' ';
		}
		
		std::cout << '\n';
		std::cout << n / 2 + 1 << '\n';
		for (long long int i = 1; i <= n / 2; i += 2) {
			std::cout << i << ' ' << n - i << ' ';
		}
	}
	else {
		std::cout << n / 2 << '\n';
		for (long long int i = 1; i < n / 2; i += 2) {
			std::cout << i << ' ' << n - i + 1 << ' ';
		}
 
		std::cout << '\n';
		std::cout << n / 2 << '\n';
		for (long long int i = 2; i <= n / 2; i += 2) {
			std::cout << i << ' ' << n - i + 1 << ' ';
		}
	}
}
