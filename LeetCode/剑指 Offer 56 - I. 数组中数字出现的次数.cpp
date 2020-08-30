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
		while ((div&ret) == 0) {//不为 00 的最低位
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

		//map<int, int> m;
		//vector<int> ret;
		//for (int i : nums) {
		//	m[i]++;
		//}
		//for (int i : nums) {
		//	if (m[i] == 1) {
		//		ret.push_back(i);
		//	}
		//}
		//return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> arr = { 4,2,4,6 };
	vector<int> ret = solution->singleNumbers(arr);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}