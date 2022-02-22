/*
In factorials, there will always be more factors of 2 than 5.
Another fact is that in order to determine how many numbers are divisible by x up to n, we simply need to compute [n / x].
Now, knowing there always are more factors of 2 than 5, we need to look only after the amount of factors of 5.
To do that, we must divide n by all of 5's powers up until n (numbers can have higher powers of 5 as divisors e.g. 50). 
For example, to compute the trailing zeros of 150! we do 150 / 5 + 150 / 25 + 150 / 125 and we're done.
*/
#include <iostream>
 
int main()
{
	long long int n;
 
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
 
	long long int trailing = 0;
	long long int p = 5;
	while (n / p) {
		trailing += n / p;
		p *= 5;
	}
 
	std::cout << trailing;
}
