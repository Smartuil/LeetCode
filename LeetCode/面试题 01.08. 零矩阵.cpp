#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <deque>
using namespace std;

class Solution {
public:
	int n, m;
	vector<vector<int>> tmp;
	void setRowCol(vector<vector<int>>& matrix, int i, int j) {
		for (int k = 0; k < n; ++k) {
			matrix[i][k] = 0;
		}
		for (int h = 0; h < m; ++h) {
			matrix[h][j] = 0;
		}
	}

	void setZeroes(vector<vector<int>>& matrix) {
		m = matrix.size();
		n = matrix[0].size();
		tmp = matrix;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					setRowCol(tmp, i, j);
				}
			}
		}
		matrix = tmp;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<vector<int>> matrix = {
		{1,1,3},
		{1,0,1},
		{1,1,1 }
	};
	solution->setZeroes(matrix);
	for (auto i : solution->tmp) {
		for (int j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}