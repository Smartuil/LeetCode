#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
	// 用于标记是否被列方向的皇后被攻击
	vector<int> rows;
	// 用于标记是否被主对角线方向的皇后攻击
	vector<int> hills;
	// 用于标记是否被次对角线方向的皇后攻击
	vector<int> dales;
	int n;
	// output
	vector<vector<string>> output;
	// 用于存储皇后放置的位置
	vector<int> queens;

	int solutionNum = 0;

	//判断 row 行，col 列这个位置有没有被其他方向的皇后攻击
	bool isNotUnderAttack(int row, int col) {
		// 判断的逻辑是：
		//      1. 当前位置的这一列方向没有皇后攻击
		//      2. 当前位置的主对角线方向没有皇后攻击
		//      3. 当前位置的次对角线方向没有皇后攻击
		int res = rows[col] + hills[row - col + 2 * n] + dales[row + col];
		// 如果三个方向都没有攻击的话，则 res = 0，即当前位置不被任何的皇后攻击
		return (res == 0) ? true : false;
	}

	void placeQueen(int row, int col) {
		queens[row] = col;
		rows[col] = 1;
		hills[row - col + 2 * n] = 1;  // "hill" diagonals
		dales[row + col] = 1;   //"dale" diagonals
	}

	void removeQueen(int row, int col) {
		queens[row] = 0;
		rows[col] = 0;
		hills[row - col + 2 * n] = 0;
		dales[row + col] = 0;
	}

	void addSolution() {
		vector<string> solution;
		for (int i = 0; i < n; ++i) {
			int col = queens[i];
			string sb;
			for (int j = 0; j < col; ++j) sb.append(".");
			sb.append("Q");
			for (int j = 0; j < n - col - 1; ++j) sb.append(".");
			solution.push_back(sb);
		}
		output.push_back(solution);
	}

	void backtrack(int row) {
		for (int col = 0; col < n; col++) {
			if (isNotUnderAttack(row, col)) {
				placeQueen(row, col);
				// if n queens are already placed
				if (row + 1 == n) /*addSolution();*/solutionNum++;
				// if not proceed to place the rest
				else backtrack(row + 1);
				// backtrack
				removeQueen(row, col);
			}
		}
	}

	vector<vector<string>> solveNQueens(int num) {
		n = num;
		rows.resize(n);
		hills.resize(4 * n - 1);
		dales.resize(2 * n - 1);
		queens.resize(n);

		backtrack(0);
		return output;
	}
};

int main() {
	Solution *solution = new Solution;
	int n = 0;
	//cin >> n;
	vector<vector<string>> ret = solution->solveNQueens(4);
	//for (auto tmp : ret) {
	//	for (auto tmp2 : tmp) {
	//		cout << tmp2 << " ";
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	cout << solution->solutionNum;
	return 0;
}