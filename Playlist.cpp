/*
* Playlist
* Sliding window techinque
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

	int n, x;
	int ans = 0, cur = 0;
	set<int> app;
	deque<int> sol;

	cin >> n;
	while (n--) {
		cin >> x;
		sol.push_back(x);
		if (app.count(x) == 1) {
			while (sol.front() != x) {
				app.erase(sol.front());
				sol.pop_front();
			}
			sol.pop_front();
		}
		app.insert(x);	
		ans = max(ans, (int)sol.size());
	}
	cout << ans;
}
