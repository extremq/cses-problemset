/*
* Chapter 5.4 (page 51) of this book should be all you need.
* https://cses.fi/book/
*/
#include <iostream>

#define BOARD_SIZE 7
#define DOWN 0
#define UP 1
#define RIGHT 2
#define LEFT 3

const int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int calls = 0;

void search(int move, int x, int y, int& count, int n, int restrictions[], int availabilityMatrix[][BOARD_SIZE]) {
	++calls;
	if (move == n * n - 1 && y == n - 1 && x == 0) {
		++count;
		return;
	}

	for (int d = 0; d < 4; ++d) {
		int newX = x + dx[d], newY = y + dy[d];
		if (availabilityMatrix[newY][newX] || newX < 0 || newY < 0 || newX >= n || newY >= n || (newY == n - 1 && newX == 0 && move + 1 != n * n - 1)  || (d != restrictions[move] && restrictions[move] != -1))
			continue;

		bool canLeft = (!availabilityMatrix[newY][newX - 1]) && newX - 1 >= 0;
		bool canRight = (!availabilityMatrix[newY][newX + 1]) && newX + 1 < n;
		bool canUp = (!availabilityMatrix[newY - 1][newX]) && newY - 1 >= 0;
		bool canDown = (!availabilityMatrix[newY + 1][newX]) && newY + 1 < n;

		if (canLeft && canRight && !canUp && !canDown) continue;
		else if (canDown && canUp && !canLeft && !canRight) continue;

		availabilityMatrix[newY][newX] = 1;
		search(move + 1, newX, newY, count, n, restrictions, availabilityMatrix);
		availabilityMatrix[newY][newX] = 0;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::string input;
	int restrictions[BOARD_SIZE * BOARD_SIZE] = { -1 };

	int availabilityMatrix[BOARD_SIZE][BOARD_SIZE] = { 0 };
	int count = 0;

	std::cin >> input;
	for (size_t i = 0; i < input.size(); ++i) {
		if (input[i] == 'D') {
			restrictions[i] = DOWN;
		}
		else if (input[i] == 'U') {
			restrictions[i] = UP;
		}
		else if (input[i] == 'R') {
			restrictions[i] = RIGHT;
		}
		else if (input[i] == 'L') {
			restrictions[i] = LEFT;
		}
		else {
			restrictions[i] = -1;
		}
	}

	availabilityMatrix[0][0] = 1;
	search(0, 0, 0, count, BOARD_SIZE, restrictions, availabilityMatrix);

	std::cout << count << '\n';
}
