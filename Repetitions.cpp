/*
Just keep check of the previous character when traversing. Can be done at read-time if using a char to read the input.
*/
#include <iostream>
#include <string>
 
int main()
{
	std::string input;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> input;
 
	int longest = 1;
	int current = 1;
 
	for (long long int i = 1; i < input.length(); ++i) {
		if (input[i] == input[i - 1]) {
			current += 1;
			longest = std::max(longest, current);
		}
		else {
			current = 1;
		}
	}
 
	std::cout << longest << '\n';
}
