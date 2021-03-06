#include "iostream"
#include "vector"
#include <algorithm>
#include "queue"
using namespace std;

//class Solution {
//public:
//	string getPermutation(int n, int k) {
//		string s = string("123456789").substr(0, n);
//		for (int j = 1; j < k; ++j) 
//			next_permutation(s.begin(), s.end());
//		return s;
//	}
//};
//https://leetcode-cn.com/problems/permutation-sequence/solution/c-ji-bai-100-3-xing-dai-ma-shi-xian-by-fu-guang/
class Solution {
	static const vector<int> fac;
public:
	string getPermutation(int n, int k) {
		string res;
		string s = string("123456789").substr(0, n);
		--k;
		while (k > 0)
		{
			size_t i = k / fac[n - 1];
			res.push_back(s[i]);
			s.erase(s.begin() + i);
			k %= fac[n - 1];
			--n;
		}
		return res + s;
	}
};
const vector<int> Solution::fac = { 0,1,2,6,24,120,720,5040,40320,362880,3628800 };

int main() {
	Solution *solution = new Solution;
	cout << solution->getPermutation(3, 4).c_str();

	return 0;
}