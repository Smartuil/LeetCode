#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ret;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != '.') {
					ret = findNumber(board, i, j, board[i][j]);
					if (ret) {
						return false;
					}
				}
			}
		}
		return true;
	}

	bool findNumber(vector<vector<char>>& board, int row, int col, char target) {
		for(int i = 0; i < 9; i++) {
			if (i == col) {
				continue;
			}
			if (board[row][i] == target) {
				return true;
			}
		}

		for (int i = 0; i < 9; i++) {
			if (i == row) {
				continue;
			}
			if (board[i][col] == target) {
				return true;
			}
		}

		if (0 <= row && row <= 2) {
			if (0 <= col && col <= 2) {
				return findNumberBoard(board, 0, 0, target, row, col);
			}
			if (3 <= col && col <= 5) {
				return findNumberBoard(board, 0, 3, target, row, col);
			}
			if (6 <= col && col <= 8) {
				return findNumberBoard(board, 0, 6, target, row, col);
			}
		}

		if (3 <= row && row <= 5) {
			if (0 <= col && col <= 2) {
				return findNumberBoard(board, 3, 0, target, row, col);
			}
			if (3 <= col && col <= 5) {
				return findNumberBoard(board, 3, 3, target, row, col);
			}
			if (6 <= col && col <= 8) {
				return findNumberBoard(board, 3, 6, target, row, col);
			}
		}

		if (6 <= row && row <= 8) {
			if (0 <= col && col <= 2) {
				return findNumberBoard(board, 6, 0, target, row, col);
			}
			if (3 <= col && col <= 5) {
				return findNumberBoard(board, 6, 3, target, row, col);
			}
			if (6 <= col && col <= 8) {
				return findNumberBoard(board, 6, 6, target, row, col);
			}
		}

		return false;
	}

	bool findNumberBoard(vector<vector<char>>& board, int row, int col, char target, int row_, int col_) {
		for (int i = row; i < row+3; i++) {
			for (int j = col; j < col+3; j++) {
				if (i == row_ && j == col_) {
					continue;
				}
				if (board[i][j] == target) {
					return true;
				}
			}
		}
		return false;
	}

};

int main() {
	Solution *solution = new Solution();
	vector < vector<char>> board  = {
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
	cout << solution->isValidSudoku(board);
	return 0;
}

