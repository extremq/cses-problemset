/*
	Concert tickets
	I am a bit weird to use stacks on this, but... we need to sort the whole list and then try and form pairs starting from x/2.
	If no such pair can be made, proceed with a lower left-side term. 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

int main() {
	std::ios_base::sync_with_stdio(false);
	
	int n, x, y;
	
	std::vector<int> children;
	std::stack<int> lt_mid, gt_mid;

	std::cin >> n >> x;

	for (int i = 0; i < n; ++i) {
		std::cin >> y;
		children.push_back(y);
	}

	std::sort(children.begin(), children.end());
	
	int gondolas = 0;

	for (int i = 0; i < n; ++i) {
		if (x % 2 == 0 && children[i] == x / 2) {
			int j = i;
			int count = 0;
			while (j < n && children[j] == x / 2) {
				++count;
				++j;
			}

			// add gondolas from mids
			gondolas = count / 2;

			int left_iter = 0;
			while (left_iter < i) {
				lt_mid.push(children[left_iter]);
				++left_iter;
			}

			int right_iter = n - 1;
			while (right_iter >= j) {
				gt_mid.push(children[right_iter]);
				--right_iter;
			}

			if (count % 2) {
				gt_mid.push(children[i]);
			}

			break;
		}
		else if (children[i] > x / 2) {
			int left_iter = 0;
			while (left_iter < i) {
				lt_mid.push(children[left_iter]);
				++left_iter;
			}

			int right_iter = n - 1;
			while (right_iter >= i) {
				gt_mid.push(children[right_iter]);
				--right_iter;
			}
			break;
		}
		else if (i == n - 1) {
			std::cout << n / 2 + n % 2 << '\n';
			return 0;
		}
	}

	//while (!lt_mid.empty()) {
	//	std::cout << lt_mid.top() << ' ';
	//	lt_mid.pop();
	//}
	//std::cout << '\n';
	//while (!gt_mid.empty()) {
	//	std::cout << gt_mid.top() << ' ';
	//	gt_mid.pop();
	//}
	//std::cout << '\n';

	int left_over = 0;
	while (true) {
		if (lt_mid.size() > 0 && gt_mid.size() > 0) {
			if (lt_mid.top() + gt_mid.top() <= x) {
				lt_mid.pop();
				gt_mid.pop();
				++gondolas;
			}
			else {
				lt_mid.pop();
				++left_over;
			}
		}
		else if (lt_mid.size() == 0) {
			gondolas += gt_mid.size();
			break;
		}
		else if (gt_mid.size() == 0) {
			gondolas += lt_mid.size() / 2;
			left_over += lt_mid.size() % 2;
			break;
		}
	}

	gondolas += left_over / 2 + left_over % 2;
	std::cout << gondolas << '\n';
}
