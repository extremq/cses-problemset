/*
* Maximum Subarray Sum
* Classic problem
*/

#include <iostream>

int main() {
    long long n, max, s = 0;
    
    std::cin >> n;

    long long x;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (i == 0) {
            max = x;
        }

        if (s + x < 0) {
            s = 0;
            max = std::max(max, x);
        }
        else {
            s += x;
            max = std::max(max, s);
        }
    }

    std::cout << max << '\n';
}
