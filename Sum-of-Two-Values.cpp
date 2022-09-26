/*
    Sum of Two Values
    Easily solvable by sorting a vector and its indices and then performing a pointer search or a binary search.
    If you're really lazy, just use a map. Store all the previous numbers encountered and perform a log(n) existence check of the counter-sum.
*/

#include <iostream>
#include <map>

int input[20000], indices[20000];

int main() {
    int n, x;

    std::cin >> n >> x;

    std::map<int, int> val;
    int input;

    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        if (val.count(x - input)) {
            std::cout << val[x - input] << ' ' << i + 1 << '\n';
            return 0;
        }
        val[input] = i + 1;
    }
    
    std::cout << "IMPOSSIBLE\n";
    
}
