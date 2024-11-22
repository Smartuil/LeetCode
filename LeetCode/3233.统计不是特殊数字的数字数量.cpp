#include "iostream"
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
	int nonSpecialCount(int l, int r) {
		int n = sqrt(r);
		vector<int> v(n + 1);
		int res = r - l + 1;
		for (int i = 2; i <= n; i++) {
			if (v[i] == 0) {
				if (i * i >= l && i * i <= r) {
					res--;
				}
				for (int j = i * 2; j <= n; j += i) {
					v[j] = 1;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution();
	cout << solution->nonSpecialCount(4, 19);

	return 0;
}