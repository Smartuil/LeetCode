#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	//bool nextStep(vector<vector<char>>& board, vector<vector<bool>>& boardCanuse, char word, char newtWord, int row, int column, int &retRow, int &retColumn) {
	//	//上
	//	if (row > 0 && column > 0) {

	//	}
	//	//下
	//	if (row <= board.size() && ) {

	//	}
	//}

	//void findLocation(vector<vector<char>>& board, vector<int> &rows, vector<int> &columns, char word) {
	//	for (int i = 0; i < board.size(); i++) {
	//		for (int j = 0; j < board[i].size(); j++) {
	//			if (board[i][j] == word) {
	//				rows.push_back(i);
	//				columns.push_back(j);
	//			}
	//		}
	//	}
	//}

	//bool exist(vector<vector<char>>& board, string word) {
	//	vector<int> rows;
	//	vector<int> columns;
	//	int retRow = 0;
	//	int retColumn = 0;
	//	vector<vector<bool>> boardCanuse(board.size(), vector<bool>(board[0].size(), 0));
	//	for (int i = 0; i < word.size()-1; i++) {
	//		rows.clear();
	//		columns.clear();
	//		findLocation(board, rows, columns, word[i]);
	//		for (int j = 0; i < rows.size(); j++) {
	//			nextStep(board, boardCanuse, word[i], word[i + 1], rows[j], columns[j], retRow, retColumn);
	//		}
	//		
	//	}

	//	return false;
	//}

	bool recursion(int i, int j, int index, vector<vector<int>> &flag, vector<vector<char>>& board, string &word) {
		if (i<0 || i>row - 1 || j<0 || j>col - 1) {
			return false;
		}
		else if (board[i][j] == word[index] && flag[i][j] == 0) {
			if (index == len - 1) {
				return true;
			}
			else
			{
				flag[i][j] = 1;
				//recursion(i + 1, j, index + 1, flag, board, word);
				//recursion(i - 1, j, index + 1, flag, board, word);
				//recursion(i, j + 1, index + 1, flag, board, word);
				//recursion(i, j - 1, index + 1, flag, board, word);
				if ((recursion(i + 1, j, index + 1, flag, board, word) ||//下
					recursion(i - 1, j, index + 1, flag, board, word) ||//上
					recursion(i, j + 1, index + 1, flag, board, word) ||//右
					recursion(i, j - 1, index + 1, flag, board, word)) == false) {//左
					flag[i][j] = 0;
					return false;
				}
				else
				{
					return true;
				}
			}
		}
		else
		{
			return false;
		}
	}

	bool exist(vector<vector<char>>& board, string word) {
		row = board.size();
		col = board[0].size();
		len = word.size();
		int index = 0;

		vector<vector<int>> flag(row, vector<int>(col, 0));

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (board[i][j] = word[index]) {
					bool temp = recursion(i, j, index, flag, board, word);
					if (temp == true) {
						return temp;
					}
				}
			}
		}
		return false;
	}

private:
	int row, col;
	int len;      //word的长度 
};

int main() {
	Solution *solution = new Solution();
	vector<vector<char>> board = { {'a'}
		//{'A', 'B', 'C', 'E' }, 
		//{'S', 'F', 'C', 'S'},
		//{'A', 'D', 'E', 'E'}
	};
	
	cout << solution->exist(board, "b");
	return 0;
}