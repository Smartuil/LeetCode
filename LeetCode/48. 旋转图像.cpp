#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int tmp;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = i; j < matrix.size(); j++) {
				tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}

		int i = 0, j = matrix.size() - 1;
		while (i < j) {
			for (int m = 0; m < matrix.size(); m++) {
				tmp = matrix[m][i];
				matrix[m][i] = matrix[m][j];
				matrix[m][j] = tmp;
			}
			i++;
			j--;
		}
	}
};

int main() {
	Solution *solution = new Solution();
	vector<vector<int>> matrix = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 9}
	};
	solution->rotate(matrix);
	cout << "[" << endl;
	for (auto i : matrix) {
		cout << "[";
		for (auto j : i) {
			cout << j;
		}
		cout << "]" << endl;
	}
	cout << "]";
	return 0;
}