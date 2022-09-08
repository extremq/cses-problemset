/*
	Tower of Hanoi problem
	I solve this using three stacks on which I place 9999 as base just for making sure I don't call stack.top() on an empty stack.
	What I've observed is that the solution is similar to binary number counting. Not only that, but I had to handle odd and even number of disks differently.
	Either way, this problem is heavily documented. No need to reinvent the wheel here. I chose the straight-forward non-recursive approach.
*/

#include <iostream>
#include <stack>

int main() {
	std::ios_base::sync_with_stdio(false);
	
	std::stack<int> pole1, pole2, pole3;

	int n;
	
	std::cin >> n;
	
	pole1.push(9999);
	pole2.push(9999);
	pole3.push(9999);

	for (int i = n; i > 0; --i) {
		pole1.push(i);
	}

	int operations = (1 << n) - 1;
	int type = 0; // Can have type 0, 1, 2 meaning the kind of exchange between the poles.
	int a, b; // Placeholders for peaks
	std::cout << operations << '\n';
	while (operations--) {
		if ((type == 0 && n % 2 == 0) || (type == 1 && n % 2 == 1)) {
			// Pole1 and Pole2 exchange
			a = pole1.top();
			b = pole2.top();
			if (a > b) {
				pole1.push(b);
				pole2.pop();
				std::cout << "2 1\n";
			}
			else {
				pole2.push(a);
				pole1.pop();
				std::cout << "1 2\n";
			}
		}
		else if ((type == 1 && n % 2 == 0) || (type == 0 && n % 2 == 1)){
			// Pole1 and Pole3 exchange
			a = pole1.top();
			b = pole3.top();
			if (a > b) {
				pole1.push(b);
				pole3.pop();
				std::cout << "3 1\n";
			}
			else {
				pole3.push(a);
				pole1.pop();
				std::cout << "1 3\n";
			}
		}
		else if (type == 2) {
			// Pole2 and Pole3 exchange
			a = pole2.top();
			b = pole3.top();
			if (a > b) {
				pole2.push(b);
				pole3.pop();
				std::cout << "3 2\n";
			}
			else {
				pole3.push(a);
				pole2.pop();
				std::cout << "2 3\n";
			}
		}
		
		type++;
		type %= 3;
	}
}
