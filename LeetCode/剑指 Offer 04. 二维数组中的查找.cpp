#include "iostream"
#include "string"
#include "vector"
#include <Windows.h>
using namespace std;

class Solution {
public:
	/*bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return false;
		}
		int row = matrix.size();
		int colum = matrix[0].size();

		int rowIndex = 0;
		bool isFind = false;

		int i = 0, j = 0;
		while (i < row) {
			while (j < colum) {
				if (matrix[i][i] < target) {
					i++;
					j++;
				}
				else if(matrix[i][i] == target)
				{
					return true;
				}
				else
				{
					for (int m = 0; m < row; m++) {
						if (matrix[m][j] == target) {
							isFind = true;
							return true;
						}
					}
					for (int n = 0; n < colum; n++) {
						if (matrix[i][n] == target) {
							isFind = true;
							return true;
						}
					}
					if (i == row - 1 && j == colum - 1) {
						i++;
						j++;
					}
				}


			}
		}

		return isFind;
	}*/

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		int i = matrix.size() - 1, j = 0;
		while (i >= 0 && j < matrix[0].size())
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] > target) i--;
			else j++;
		return false;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<vector<int>> matrix = { 
		{1,   4,  7, 11, 15 },
		{2,   5,  8, 12, 19 },
		{3,   6,  9, 16, 22 },
		{10, 13, 14, 17, 24 },
		{18, 21, 23, 26, 30 }
	};
	cout << solution->findNumberIn2DArray(matrix, 30);
	return 0;
}