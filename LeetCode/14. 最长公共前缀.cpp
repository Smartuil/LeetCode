#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
using namespace std;

//class Solution {
//public:
//	string longestCommonPrefix(vector<string>& strs) {
//		if (strs.empty()) {
//			return "";
//		}
//		if (strs.size() == 1) {
//			return strs[0];
//		}
//		int minLen = strs[0].size();
//		string ret;
//		for (int i = 1; i < strs.size(); i++) {
//			if (strs[i].size() < minLen) {
//				minLen = strs[i].size();
//			}
//		}
//
//		for (int i = 0; i < minLen; i++) {
//			bool find = false;
//			for (int j = 1; j < strs.size(); j++) {
//				if(strs[0][i] == strs[j][i])
//				{
//					if (j == strs.size() - 1) {
//						find = true;
//					}
//					continue;
//				}
//				else
//				{
//					break;
//				}
//			}
//			if (find == true) {
//				ret.push_back(strs[0][i]);
//			}
//			else if(i == 0)
//			{
//				break;
//			}
//		}
//
//		return ret.size() > 0 ? ret : "";
//	}
//};

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (!strs.size()) {
			return "";
		}
		string prefix = strs[0];
		int count = strs.size();
		for (int i = 1; i < count; ++i) {
			prefix = longestCommonPrefix(prefix, strs[i]);
			if (!prefix.size()) {
				break;
			}
		}
		return prefix;
	}

	string longestCommonPrefix(const string& str1, const string& str2) {
		int length = min(str1.size(), str2.size());
		int index = 0;
		while (index < length && str1[index] == str2[index]) {
			++index;
		}
		return str1.substr(0, index);
	}
};

int main() {
	Solution *solution = new Solution();
	vector<string> strs = { "flower","flow","flight" };
	cout << solution->longestCommonPrefix(strs);
	return 0;
}