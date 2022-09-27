/*
* Towers
* Using a multiset, I can keep track of multiple towers. I just store the top of them then do a upper-bound search on the cube i want to place.
* If there is nowhere to place the cube, I must begin a new tower.
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>
#include <utility>

#define ll long long
#define vi vector<int>
#define nl '\n'
#define sp ' '
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/* BEGIN PROBLEM */

	multiset<int> towers;
	int n, x;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (i == 0) {
			towers.insert(x);
		}
		else {
			auto it = towers.upper_bound(x);
			if (it == towers.end())	{
				towers.insert(x);
			}
			else {
				towers.erase(it);
				towers.insert(x);
			}
		}
	}
	cout << towers.size();
}
