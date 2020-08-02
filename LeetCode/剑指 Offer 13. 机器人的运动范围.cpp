#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	//bool LowK(int m, int n, int k, vector<vector<int>> &flag) {
	//	int m_baiwei = m / 100;
	//	int n_baiwei = n / 100;
	//	m %= 100;
	//	n %= 100;
	//	int m_shiwei = m / 10;
	//	int n_shiwei = n / 10;
	//	m %= 10;
	//	n %= 10;
	//	if ((m_baiwei + n_baiwei + m_shiwei + n_shiwei + m + n <= k)&&) {
	//		return true;
	//	}
	//	return false;
	//}

	//int movingCount(int m, int n, int k) {
	//	vector<vector<int>> flag(m, vector<int>(n, 0));
	//	int count = 0;
	//	for (int i = 0; i < m; i++) {
	//		for (int j = 0; j < n; j++) {
	//			if (LowK(i, j, k, flag)) {
	//				flag[i][j] = 1;
	//				count++;
	//			}
	//		}
	//	}
	//	return count;

	//}

	int movingCount(int m, int n, int k) {
		vector<vector<int>> flag(m, vector<int>(n, 0));
		return dfs(0, 0, m, n, k, flag);
	}

	int dfs(int i, int j, int m, int n, int k, vector<vector<int>>& flag) {
		if (i<0 || i>m - 1 || j<0 || j>n - 1 || (i / 100 + i / 10 + i % 10 + j / 100 + j / 10 + j % 10) > k || flag[i][j] == 1) {
			return 0;
		}

		flag[i][j] = 1;
		return dfs(i + 1, j, m, n, k, flag) +
			dfs(i, j + 1, m, n, k, flag) +
			dfs(i - 1, j, m, n, k, flag) +
			dfs(i, j - 1, m, n, k, flag) + 1;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->movingCount(16, 8, 4);
	return 0;
}