#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	// box size
	int n = 3;
	// row size
	int N = n * n;

	int rows[9][10] ;
	int columns[9][10];
	int boxes[9][10];

	bool sudokuSolved = false;

	bool couldPlace(int d, int row, int col) {
		/*
		Check if one could place a number d in (row, col) cell
		*/
		int idx = (row / n) * n + col / n;
		return rows[row][d] + columns[col][d] + boxes[idx][d] == 0;
	}

	void placeNumber(int d, int row, int col, vector<vector<char>>& board) {
		/*
		Place a number d in (row, col) cell
		*/
		int idx = (row / n) * n + col / n;

		rows[row][d]++;
		columns[col][d]++;
		boxes[idx][d]++;
		board[row][col] = (char)(d + '0');
	}

	void removeNumber(int d, int row, int col, vector<vector<char>>& board) {
		/*
		Remove a number which didn't lead to a solution
		*/
		int idx = (row / n) * n + col / n;
		rows[row][d]--;
		columns[col][d]--;
		boxes[idx][d]--;
		board[row][col] = '.';
	}

	void placeNextNumbers(int row, int col, vector<vector<char>>& board) {
		/*
		Call backtrack function in recursion
		to continue to place numbers
		till the moment we have a solution
		*/
		// if we're in the last cell
		// that means we have the solution
		if ((col == N - 1) && (row == N - 1)) {
			sudokuSolved = true;
		}
		// if not yet
		else {
			// if we're in the end of the row
			// go to the next row
			if (col == N - 1) backtrack(row + 1, 0, board);
			// go to the next column
			else backtrack(row, col + 1, board);
		}
	}

	void backtrack(int row, int col, vector<vector<char>>& board) {
		/*
		Backtracking
		*/
		// if the cell is empty
		if (board[row][col] == '.') {
			// iterate over all numbers from 1 to 9
			for (int d = 1; d < 10; d++) {
				if (couldPlace(d, row, col)) {
					placeNumber(d, row, col, board);
					placeNextNumbers(row, col, board);
					// if sudoku is solved, there is no need to backtrack
					// since the single unique solution is promised
					if (!sudokuSolved) removeNumber(d, row, col, board);
				}
			}
		}
		else placeNextNumbers(row, col, board);
	}

	void solveSudoku(vector<vector<char>>& board) {

		// init rows, columns and boxes
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				char num = board[i][j];
				if (num != '.') {
					int d = num - '0';
					placeNumber(d, i, j, board);
				}
			}
		}
		backtrack(0, 0, board);
	}
};

int main() {
	Solution *solution = new Solution();
	vector < vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.' ,'8' ,'.' ,'.' ,'7' ,'9'}
	};
	solution->solveSudoku(board);
	for (auto i : board) {
		for (auto j : i) {
			cout << "'" << j<< "', ";
		}
		cout << endl;
	}
	return 0;
}