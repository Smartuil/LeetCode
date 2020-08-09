#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		int ret = 0;
		for (int i : nums) {
			ret ^= i;
		}
		int div = 1;
		while ((div&ret) == 0) {
			div <<= 1;
		}
		int a = 0, b = 0;
		for (int i : nums) {
			if (div&i) {
				a ^= i;
			}
			else
			{
				b ^= i;
			}
		}
		return vector<int>{a, b};
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> arr = { 4,1,4,6 };
	vector<int> ret = solution->singleNumbers(arr);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}