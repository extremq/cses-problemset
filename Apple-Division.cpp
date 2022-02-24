/*
* The size of the list can be at most 20. If we were to try all possible combinations, that would resolve to 2^20.
* 2^20 ~ 1000000, and that's a ton of time.
* I traverse each number from 0 to 2^20 and check the bits of each one.
* For each number, if the i-th bit is set, then I add the i-th list member.
* Check this example:
* 5
* 3 2 7 4 1
* Now, I will iterate from 0 to 2^5 = 32.
* For example, if I reach 6 (00110 in binary) then I will be adding 2 and 7 = 9. The rest of the sum is the total sum - the secondary sum = 8.
* The difference between the two sums is 1, the minimum. Also, the formula is totalSum - 2 * partialSum for the difference.
* However, we introduce one optimisation.
* If the partial sum is > total sum / 2, then I skip. I already go through all of the possible sums, so that means I will both go through the smaller sum and
* the higher sum. Take, for example, 01100 = 12. The partial sum will be equal to 7 + 4 which is bigger than 17 / 2 (tSum / 2).
* I will also check 10011, the inverse, at some point. This essentially halves the computation.
*
* To be noted, I think we could just go until 2^(n-1) and have this optimisation removed.
*/
#include <iostream>
#include <vector>

void groupSum(const long long int& tSum, long long int& gSum, long long int& minimum, const std::vector<long long int>& input, int iter, int n) {
	gSum = 0;
	for (int i = 0; i < n; ++i) {
		if (1 << i & iter) {
			gSum += input[i];
			if (gSum > tSum / 2) {
				return;
			}
		}
	}
	minimum = std::min(tSum - 2 * gSum, minimum);
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	long long int x, gSum, tSum = 0, minimum = 9999999999999999;
	std::vector<long long int> input;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		tSum += x;

		input.push_back(x);
	}

	int upperLim = 1 << n;
	for (int i = 0; i < upperLim; ++i) {
		groupSum(tSum, gSum, minimum, input, i, n);
	}

	std::cout << minimum;
}
