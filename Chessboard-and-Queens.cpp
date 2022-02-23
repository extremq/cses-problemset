/*
* Chapter 5.3 (page 50) of this book should be all you need. 
* https://cses.fi/book/
*/
#include <iostream>

#define BOARD_SIZE 8

void search(int row, int& count, int n, int availabilityMatrix[][BOARD_SIZE], int colOccupance[], int diagOccupance[], int antiDiagOccupance[]) {
	if (row == n) {
		++count;
		return;
	}

	for (int column = 0; column < n; ++column) {
		if (availabilityMatrix[row][column] || colOccupance[column] || diagOccupance[column + row] || antiDiagOccupance[column - row + n - 1])
			continue;

		colOccupance[column] = diagOccupance[column + row] = antiDiagOccupance[column - row + n - 1] = 1;
		search(row + 1, count, n, availabilityMatrix, colOccupance, diagOccupance, antiDiagOccupance);
		colOccupance[column] = diagOccupance[column + row] = antiDiagOccupance[column - row + n - 1] = 0;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);

	std::string input;

	int availabilityMatrix[BOARD_SIZE][BOARD_SIZE] = { 0 };
	int columnOccupance[BOARD_SIZE] = { 0 };
	int diagonalOccupance[2 * BOARD_SIZE] = { 0 };
	int antiDiagonalOccupance[2 * BOARD_SIZE] = { 0 };
	int count = 0;

	for (int i = 0; i < BOARD_SIZE; ++i) {
		std::cin >> input;
		
		for (size_t j = 0; j < input.size(); ++j) {
			if (input[j] == '*') {
				availabilityMatrix[i][j] = 1;
			}
		}
	}

	search(0, count, BOARD_SIZE, availabilityMatrix, columnOccupance, diagonalOccupance, antiDiagonalOccupance);

	std::cout << count << '\n';
}
