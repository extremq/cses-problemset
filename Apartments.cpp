/*
	Apartments
	Sort both arrays. Now, imagine a plane on which there are vertical lines for each apartment size while there are horizontal
	lines for the range of the buyer's prefference (x - k, x + k). Going from left to right, we can check whether any of the 
	prefferences intersect the first line. If one does, we go to the next vertical line and see if we can find anything intersecting it.
	Sorting is necessary here.
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	
	int n, m, k;
	
	std::vector<int> pref_sizes;
	std::vector<int> ap_sizes;

	std::cin >> n >> m >> k;

	int x;

	for (int i = 0; i < n; ++i) {
		std::cin >> x;
		pref_sizes.push_back(x);
	}

	for (int i = 0; i < m; ++i) {
		std::cin >> x;
		ap_sizes.push_back(x);
	}

	std::sort(pref_sizes.begin(), pref_sizes.end());
	std::sort(ap_sizes.begin(), ap_sizes.end());

	int iter_ap = 0, iter_pref = 0, tenants = 0;
	while (iter_ap < m && iter_pref < n) {
		int cur_pref = pref_sizes[iter_pref];
		int cur_ap = ap_sizes[iter_ap];

		//std::cout << "Checking " << cur_ap << ' ' << cur_pref << ' ' << k << '\n';

		if (cur_pref - k <= cur_ap && cur_ap <= cur_pref + k) {
			// If inside the buyer range
			++iter_ap;
			++tenants;
		}
		else if (cur_pref - k > cur_ap) {
			++iter_ap;
			--iter_pref;
		}

		++iter_pref;
	}

	std::cout << tenants << '\n';
}
