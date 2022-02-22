/*
 1  2  9 10 25
 4  3  8 11 24
 5  6  7 12 23
16 15 14 13 22
17 18 19 20 21
Notice how the columns and the lines start. Either it's a perfect square or 1 less or 1 more than a perfect square.
It's important that we pick the bigger number between y and x.
For example, if the input is 2 5, we must solve the problem by looking at the column 5 since it assures that
we can go 2 steps down just by subtracting 2 - 1 (the index starts at 1).
There are two cases for each of the two cases regarding parity.
If the column is bigger, then odd columns mean perfect squares (x^2), otherwise even columns mean (x - 1) ^ 2 - 1.
You can derive some similar rules for the rows.
*/
#include <iostream>
 
int main()
{
	int q;
	long long int n, m;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> q;
	
	long long int answer;
	while (q--) {
		std::cin >> n >> m;
		
		if (n > m) {
			if (n & 1) {
				answer = (n - 1) * (n - 1) + m;
			}
			else {
				answer = n * n - m + 1;
			}
		}
		else if(n < m) {
			if (m & 1) {
				answer = m * m - n + 1;
			}
			else {
				answer = (m - 1) * (m - 1) + n;
			}
		}
		else {
			answer = n * (n - 1) + 1;
		}
 
		std::cout << answer << '\n';
	}
}
