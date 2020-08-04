#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) {
			return {};
		}
		if (matrix.size() == 1) {
			return matrix[0];
		}
		vector<int> ret;
		int top = 0;
		int down = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;
		while (left <= right && top <= down)
		{
			for (int i = left; i <= right; i++) {
				ret.push_back(matrix[top][i]);
			}
			
			for (int j = top+1; j <= down; j++) {
				ret.push_back(matrix[j][right]);
			}
			if(left < right&&top < down) {
				for (int i = right-1; i > left; i--) {
					ret.push_back(matrix[down][i]);
				}

				for (int j = down; j > top; j--) {
					ret.push_back(matrix[j][left]);
				}
			}


			top++;
			right--;
			left++;
			down--;
		}

		return ret;
	}
};

int main() {
	Solution *solution = new Solution;
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	vector<int> ret = solution->spiralOrder(matrix);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}