#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	//int maxValue(vector<vector<int>>& grid) {
	//	int m = grid.size(), n = grid[0].size();
	//	for (int j = 1; j < n; j++) // 初始化第一行
	//		grid[0][j] += grid[0][j - 1];
	//	for (int i = 1; i < m; i++) // 初始化第一列
	//		grid[i][0] += grid[i - 1][0];
	//	for (int i = 1; i < m; i++)
	//		for (int j = 1; j < n; j++)
	//			grid[i][j] += max(grid[i][j - 1], grid[i - 1][j]);
	//	return grid[m - 1][n - 1];
	//}
	int maxValue(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		for (int i = 1; i < n; ++i) {
			grid[0][i] += grid[0][i - 1];
		}
		for (int j = 1; j < m; ++j) {
			grid[j][0] += grid[j - 1][0];
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
			}
		}
		return grid[m - 1][n - 1];
	}

};

int main() {
	Solution *solution = new Solution();
	vector<vector<int>> grid = { {1,3,1},{1,5,1},{4,2,1} };
	cout << solution->maxValue(grid);
	return 0;
}