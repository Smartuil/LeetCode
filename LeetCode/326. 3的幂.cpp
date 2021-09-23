#include "iostream"

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		return n > 0 && 1162261467 % n == 0;
	}
};

int main()
{
	Solution* solution = new Solution();
	cout << solution->isPowerOfThree(33);

	return 0;
}