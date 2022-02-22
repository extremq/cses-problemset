/*
We have n^2 choose 2 ways of placing the two knights.
Knights attack in L patterns, so by fitting the board with several 2x3 and 3x2 rectangles,
we can determine how many invalid placements there exist on a given board.
*/
#include <iostream>
 
int main()
{
	long long int n;
	long long int positions;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	std::cout << 0 << '\n';
	for (long long int i = 2; i <= n; ++i) {
		positions = (i * i) * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2);
		
		std::cout << positions << '\n';
	}
}
