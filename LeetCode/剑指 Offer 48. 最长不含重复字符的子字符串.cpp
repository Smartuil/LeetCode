#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int len = 0;
//		int tmp = 0;
//		string current_s;
//		for (int i = 0; i < s.length(); i++) {
//			current_s = s[i];
//			if (i == s.length() - 1) {
//				tmp = 1;
//				break;
//			}
//			for (int j = i + 1; j <= s.length(); j++) {
//				if (j == s.length()) {
//					break;
//				}
//				string::size_type idx = current_s.find(s[j]);
//				if (idx == string::npos) {
//					tmp = j - i + 1;
//					if (tmp > len) {
//						len = tmp;
//					}
//					current_s += s[j];
//				}
//				else {
//					tmp = 1;
//					break;
//				}
//			}
//		}
//		return tmp > len ? tmp : len;
//	}
//};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// 哈希集合，记录每个字符是否出现过
		unordered_set<char> occ;
		int n = s.size();
		// 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
		int rk = -1, ans = 0;
		// 枚举左指针的位置，初始值隐性地表示为 -1
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				// 左指针向右移动一格，移除一个字符
				occ.erase(s[i - 1]);
				//occ.erase(occ.begin());
			}
			while (rk + 1 < n && !occ.count(s[rk + 1])) {
				// 不断地移动右指针
				occ.insert(s[rk + 1]);
				++rk;
			}
			// 第 i 到 rk 个字符是一个极长的无重复字符子串
			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};

//class Solution {
//public:
	int lengthOfLongestSubstring2(string s) {
		unordered_set<char> occ;
		int ret = 0;
		int rk = -1;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			if (i != 0) {
				occ.erase(occ.begin());
			}
			while (rk + 1 < n && !occ.count(s[rk + 1])) {
				occ.insert(s[rk + 1]);
				++rk;
			}
			ret = max(ret, rk - i + 1);
		}
		return ret;
	}


	//https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solution/tu-jie-hua-dong-chuang-kou-shuang-zhi-zhen-shi-xia/
int lengthOfLongestSubstring(string s) {
	map<char, int> m;
	int ret = 0, l = 0, r = 0;
	while (r < s.size()) {
		if (m.find(s[r]) != m.end()) {
			l = max(l, m[s[r]] + 1);
		}
		m[s[r++]] = r;
		ret = max(r - l, ret);
	}
	return ret;
}

//};

int main() {
	Solution *solution = new Solution();
	cout << /*solution->*/lengthOfLongestSubstring2("pwwkew");
	return 0;
}