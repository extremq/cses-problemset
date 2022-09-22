/*
	Restaurant Customers
    Basically arrange a list of all customers by arriving time in increasing order (in a c++ set), then add them one by one in another set 
    that is sorted by departure time in increasing order. Every time we add a customer in the other set, we eliminate all customers at the beginning
    that have departure times lower than the new customer's arrival time.
*/

#include <iostream>
#include <set>
#include <algorithm>

struct segment {
    int start, end;
};

bool comp1(segment a, segment b) {
    return a.start < b.start;
}


bool comp2(segment a, segment b) {
    return a.end < b.end;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::multiset<segment, decltype(&comp1)> init(&comp1);
    std::multiset<segment, decltype(&comp2)> overlap(&comp2);
    segment input;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> input.start >> input.end;
        init.insert(input);
    }

    int max_overlap = 0;

    for (auto it = init.begin(); it != init.end(); ++it) {
        if (it == init.begin()) {
            overlap.insert(*it);
        }
        else {
            overlap.insert(*it);
            while (it->start >= overlap.begin()->end) {
                overlap.erase(overlap.begin());
            }

            max_overlap = std::max(max_overlap, (int) overlap.size());
        }
    }

    /*for (auto it = overlap.begin(); it != overlap.end(); ++it) {
        std::cout << it->start << ' ' << it->end << '\n';
    }*/

    std::cout << max_overlap << '\n';
}
