#include "iostream"
#include "string"
#include "vector"
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		if (words.size() == 0) return {};
		unordered_map<string, int> wordcnt;
		for (auto& w : words)
		{
			wordcnt[w]++;
		}
		int len = words[0].size();

		vector<int> ans;
		for (int i = 0; i < len; i++)
		{
			int left = i;
			int right = left;
			int cnt = 0;

			unordered_map<string, int> window;
			while (left + words.size() * len <= s.size())
			{
				string temp = "";
				while (cnt < words.size())
				{
					temp = s.substr(right, len);
					if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
					window[temp]++;
					cnt++;
					right += len;
				}

				if (window == wordcnt)
				{
					ans.push_back(left);
				}

				if (wordcnt.find(temp) != wordcnt.end())
				{
					window[s.substr(left, len)]--;
					cnt--;
					left += len;
				}
				else
				{
					right += len;
					left = right;
					cnt = 0;
					window.clear();
				}
			}
		}
		return ans;
	}
};


/*
*³¬Ê±
*/
//class Solution {
//public:
//	vector<int> findSubstring(string s, vector<string>& words) {
//		vector<int> result;
//		if (s.size() <= 0 || words.size() <= 0 || words.begin()->size() <= 0)
//			return result;
//		int wlen = words.begin()->size();
//		int wcot = words.size();
//		if (wlen * wcot > s.size()) return result;
//		sort(words.begin(), words.end());
//		vector<string> buff;
//		for (int i = 0; i <= s.size() - (wlen*wcot); i++) {
//			stepSplit(&s, i, wlen, wcot, &buff);
//			sort(buff.begin(), buff.end());
//			if (buff == words) result.push_back(i);
//			buff.clear();
//		}
//		return result;
//
//	}
//	void stepSplit(string *s, int i, int k, int n, vector<string> *result) {
//		while (n--) {
//			result->push_back(s->substr(i, k));
//			i += k;
//		}
//	}
//
//};

int main() {
	Solution *solution = new Solution();
	vector<string> words = {"foo", "bar"};
	vector<int> ret = solution->findSubstring("barfoothefoobarman", words);
	//for (auto i : ret) {
	//	cout << i;
	//}
	return 0;
}