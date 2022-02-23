/*
* Imagine how the numbers are grouped based on the amount of their digits:
* Firstly, we have the 1-digit group, then the 2-digit group and so on.
* The 1-digit group has 9 numbers. The 2-digit group has 90 numbers. The 3-digit group has 900 numbers.
* The amount of digits they take up is just a multiplication. 
* 2 * 90 = 180 digits taken up by 2-digit numbers.
* Well, now imagine i throw you an n. It must be in one of these groups, but how do we know?
* Just make a partial sum vector containing the amount of digits taken up by each group.
* partial[0] = 0 (0 digits take up 0 digits)
* partial[1] = 9 (1-digit take up 9 digits)
* partial[2] = partial[1] + 180 = 189
* partial[3] = partial[1] + partial[2] + 900 = 2889
* .
* .
* Until we reach 10^18 digits, that being the upper bound on n.
* Now, each time we are given an n, simply search through the partial sum array. When you get to a partial sum higher than n,
* it means you have one less digit than of that group.
* For example, take 200. 200 > 189 but 200 < 2889, so that means it's in the 3 digit group.
* Knowing that, we simply divide the offset by the number of digits of the group and add the highest lesser digit number.
* When n = 200, we compute the offset by subtracting 189 from 200 = 11.
* Divide 11 by 3 = 3, remainder 2. Since the remainder is non-zero, it means this is the 3 + 1th number, or the fourth 3-digit number (103).
* If 189 digits are taken up by all 2 digit numbers, it means that 190 is the first digit of 100.
* 100 101 102 103
*              ^ is the 11th digit counting from 190, the first 1.
* We add up 99 with the result from the division (11 / 3 = 3) and also increment by 1 (don't forget the remainder).
* Then, using the remainder we can trivially obtain the digit.
*/
#include <iostream>
#include <vector>
#include <math.h>

int main()
{
	long long int q, n;

	std::ios_base::sync_with_stdio(false);
	std::cin >> q;

	std::vector<long long int> computedDigits;

	long long int count = 0;
	long long int upperBound = 1LL << 60;
	long long int order = 10, previousOrder = 1;
	long long int digits = 1;

	computedDigits.push_back(0);
	while (count < upperBound) {
		count += (order - previousOrder) * digits;
		previousOrder = order;

		computedDigits.push_back(count);

		order *= 10;
		digits += 1;
	}

	long long int number, offset, digit, remainder;
	while (q--) {
		std::cin >> n;

		for (long long int i = 0; i < computedDigits.size(); ++i) {
			if ((i + 1 < computedDigits.size() && n < computedDigits[i + 1]) || (i + 1 == computedDigits.size())) {
				offset = n - computedDigits[i];
				number = offset / (i + 1) + (long long int) pow(10, i) - 1;
				if (offset % (i + 1))
					number += 1;
				remainder = offset % (i + 1);
				if (remainder == 0) {
					digit = number % 10;
				}
				else {
					digit = number / (long long int) pow(10, i + 1 - remainder) % 10;
				}
				std::cout << digit << '\n';
				break;
			}
		}
	}

}
