/*
The problem requires that any two adjacent numbers be of the form a1 <= a2. 
Finding the minimum steps required then means adding the difference if the first number is smaller than the second.
*/
#include <iostream>
 
int main()
{
	int n;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	long long int previous, current;
	long long int steps = 0;
 
	std::cin >> previous;
 
	for (int i = 1; i < n; ++i) {
		std::cin >> current;
		
		if (current < previous) {
			steps += previous - current;
		}
		else
			previous = current;
	}
 
	std::cout << steps << '\n';
}
