#include "iostream"
#include "vector"
#include <algorithm>

using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int m1 = INT_MAX, m2 = INT_MAX;
		for (auto a : nums) {
			if (m1 >= a) m1 = a;
			else if (m2 >= a) m2 = a;
			else return true;
		}
		return false;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> A = { 5,4,3,2,1 };
	cout << solution->increasingTriplet(A);
	return 0;
}