#include "iostream"
#include "string"
#include "vector"
#include "map"
#include <algorithm>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		if (strs.empty()) {
//			return {};
//		}
//		map<char, int> index;
//		vector<vector<int>> tmp;
//		vector<int> tmp2;
//		vector<vector<string>> ret;
//		vector<string> ret2;
//		int len = strs.size();
//		index.insert(make_pair('a', 1));
//		index.insert(make_pair('b', 2));
//		index.insert(make_pair('c', 3));
//		index.insert(make_pair('d', 4));
//		index.insert(make_pair('e', 5));
//		index.insert(make_pair('f', 6));
//		index.insert(make_pair('g', 7));
//		index.insert(make_pair('h', 8));
//		index.insert(make_pair('i', 9));
//		index.insert(make_pair('j', 10));
//		index.insert(make_pair('k', 11));
//		index.insert(make_pair('l', 12));
//		index.insert(make_pair('m', 13));
//		index.insert(make_pair('n', 14));
//		index.insert(make_pair('o', 15));
//		index.insert(make_pair('p', 16));
//		index.insert(make_pair('q', 17));
//		index.insert(make_pair('r', 18));
//		index.insert(make_pair('s', 19));
//		index.insert(make_pair('t', 20));
//		index.insert(make_pair('u', 21));
//		index.insert(make_pair('v', 22));
//		index.insert(make_pair('w', 23));
//		index.insert(make_pair('x', 24));
//		index.insert(make_pair('y', 25));
//		index.insert(make_pair('z', 26));
//		for (int i = 0; i < len; i++) {
//			tmp2.clear();
//			for (int j = 0; j < strs[i].size(); j++) {
//				auto iter = index.find(strs[i][j]);
//				tmp2.push_back(iter->second);
//				sort(tmp2.begin(), tmp2.end());
//			}
//			tmp.push_back(tmp2);
//		}
//
//		int len = tmp.size();
//		vector<bool> isUse(len, false);
//		int i = 0, j = 1;
//		while(i < len) {
//			if (isUse[i] == true) {
//				i++;
//				continue;
//			}
//			j = i + 1;
//			ret2.clear();
//			ret2.push_back(strs[i]);
//			while (j < len) {
//				if (isUse[j] == true) {
//					j++;
//					continue;
//				}
//				if (tmp[i] == tmp[j]) {
//					isUse[j] = true;
//					ret2.push_back(strs[j]);
//				}
//				j++;
//			}
//			ret.push_back(ret2);
//			i++;
//		}
//		return ret;
//	}
//};

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		int sub = 0;
		string tmp;
		unordered_map<string, int> work;
		for (auto str : strs)
		{
			tmp = str;
			sort(tmp.begin(), tmp.end());
			if (work.count(tmp))
			{
				res[work[tmp]].push_back(str);
			}
			else
			{
				vector<string> vec(1, str);
				res.push_back(vec);
				work[tmp] = sub++;
			}
		}
		return res;
	}
};

int main() {
	Solution *solution = new Solution; 
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> ret = solution->groupAnagrams(strs);
	cout << "[" << endl;
	for (auto i : ret) {
		cout << "[";
		for (auto j : i) {
			cout << j;
		}
		cout << "]" << endl;
	}
	cout << "]";
	return 0;
}