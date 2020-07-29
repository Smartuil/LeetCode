#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	int num = 1;
	vector<vector<int>> generateMatrix(int n) {
		if (n == 0) {
			return{};
		}
		vector<vector<int>> ret(n, vector<int>(n));
		vector<int> tmp;
		int up = 0, down = n - 1, left = 0, right = n - 1;
		while (left <= right && up <= down) {
			for (int column = left; column <= right; column++) {
				ret[up][column] = num;
				num++;
			}
			for (int row = up+1; row <= down; row++) {
				ret[row][right] = num;
				num++;
			}
			if (left < right&&up < down) {
				for (int column = right-1; column > left; column--) {
					ret[down][column] = num;
					num++;
				}
				for (int row = down; row > up; row--) {
					ret[row][left] = num;
					num++;
				}
			}
			left++;
			right--;
			up++;
			down--;
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution;
	vector<vector<int>> ret = solution->generateMatrix(10);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j;
		}
		cout << endl;
	}
	return 0;
}