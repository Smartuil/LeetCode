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
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		// C++ ����� = ������ֵ��������õ�һ���µ�����
		auto matrix_new = matrix;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				matrix_new[j][n - i - 1] = matrix[i][j];
			}
		}
		// ����Ҳ��ֵ����
		matrix = matrix_new;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9 }
	};
	solution->rotate(matrix);
	return 0;
}