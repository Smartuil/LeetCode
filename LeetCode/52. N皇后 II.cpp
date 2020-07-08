#include "iostream"
#include "vector"
#include "string"
using namespace std;

class Solution {
public:
	// ���ڱ���Ƿ��з���Ļʺ󱻹���
	vector<int> rows;
	// ���ڱ���Ƿ����Խ��߷���Ļʺ󹥻�
	vector<int> hills;
	// ���ڱ���Ƿ񱻴ζԽ��߷���Ļʺ󹥻�
	vector<int> dales;
	int n;
	// output
	vector<vector<string>> output;
	// ���ڴ洢�ʺ���õ�λ��
	vector<int> queens;

	int solutionNum = 0;

	//�ж� row �У�col �����λ����û�б���������Ļʺ󹥻�
	bool isNotUnderAttack(int row, int col) {
		// �жϵ��߼��ǣ�
		//      1. ��ǰλ�õ���һ�з���û�лʺ󹥻�
		//      2. ��ǰλ�õ����Խ��߷���û�лʺ󹥻�
		//      3. ��ǰλ�õĴζԽ��߷���û�лʺ󹥻�
		int res = rows[col] + hills[row - col + 2 * n] + dales[row + col];
		// �����������û�й����Ļ����� res = 0������ǰλ�ò����κεĻʺ󹥻�
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