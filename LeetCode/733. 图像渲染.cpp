#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
using namespace std;

class Solution {
public:

	void order(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
		int m = image.size();
		int n = image[0].size();
		if (sr<0 || sr>m - 1 || sc<0 || sc>n - 1 || image[sr][sc] != oldColor || newColor == oldColor) {
			//通过判断和oldColor，更改过就直接跳出
			return;
		}
		image[sr][sc] = newColor;
		order(image, sr - 1, sc, newColor, oldColor);
		order(image, sr + 1, sc, newColor, oldColor);
		order(image, sr, sc + 1, newColor, oldColor);
		order(image, sr, sc - 1, newColor, oldColor);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		order(image, sr, sc, newColor, image[sr][sc]);
		return image;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<vector<int>> image = { 
		{1,1,1},
		{1,1,0},
		{1,0,1}
	};
	vector<vector<int>> ret = solution->floodFill(image, 1, 1, 2);
	for(auto i:ret)
		for (auto j : i) {
			cout << j << " ";
		}
	cout << endl;
	return 0;
}