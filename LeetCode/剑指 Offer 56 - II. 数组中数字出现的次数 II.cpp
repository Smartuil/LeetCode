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
	int singleNumber(vector<int>& nums) {
		//int ones = 0, twos = 0;
		//for (int num : nums) {
		//	ones = ones ^ num & ~twos;
		//	twos = twos ^ num & ~ones;
		//}
		//return ones;
		vector<int> count(32);
		for (int num : nums) {
			for (int i = 0; i < 32; i++) {
				count[i] += num & 1;
				num >>= 1;
			}
		}
		int res = 0;
		for (int i = 0; i < 32; i++) {
			res <<= 1;
			res |= count[31 - i] % 3;
		}
		return res;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> arr = { 3,4,3,3 };
	cout << solution->singleNumber(arr);
	return 0;
}