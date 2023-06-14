#include "iostream"
#include "vector"
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	int numTimesAllBlue(vector<int>& flips) {
		int n = flips.size();
		int ans = 0, right = 0;
		for (int i = 0; i < n; ++i) {
			right = max(right, flips[i]);
			if (right == i + 1) {
				++ans;
			}
		}
		return ans;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> flips = { 3,2,4,1,5 };
	cout << solution->numTimesAllBlue(flips);
	return 0;
}