#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	//string reverseWords1(string s) {
	//	istringstream is(s);
	//	string tmp;
	//	vector<string> tmp2;
	//	while (is >> tmp) {
	//		tmp2.push_back(tmp);
	//	}
	//	tmp.clear();
	//	for (int i = tmp2.size() - 1; i >= 0; i--) {
	//		
	//		tmp.append(tmp2[i]);
	//		if(i!=0)
	//			tmp.append(" ");
	//	}
	//	return tmp;
	//}

	////注意：当字符串为空时，也会返回一个空字符串  
	//void split(std::string s, std::string delim, std::vector< std::string >& ret)
	//{
	//	size_t last = 0;
	//	size_t index = s.find_first_of(delim, last);
	//	while (index != std::string::npos)
	//	{
	//		ret.push_back(s.substr(last, index - last));
	//		last = index + 1;
	//		index = s.find_first_of(delim, last);
	//	}
	//	if (index - last > 0)
	//	{
	//		ret.push_back(s.substr(last, index - last));
	//	}
	//}

	//string reverseWords(string s) {
	//	vector< std::string > ret = {};
	//	split(s, " ", ret);
	//	string tmp;
	//	for (int i = ret.size() - 1; i >= 0; i--) {

	//		tmp.append(ret[i]);
	//		if (i != 0)
	//			tmp.append(" ");
	//	}
	//	return trim(tmp);
	//}

	//std::string trim(std::string& s)
	//{
	//	if (s.empty())
	//	{
	//		return s;
	//	}

	//	s.erase(0, s.find_first_not_of(" "));
	//	s.erase(s.find_last_not_of(" ") + 1);
	//	return s;
	//}

	//string reverseWords2(string s) {
	//	trim(s);
	//	int j = s.size() - 1, i = j;
	//	string ret;
	//	while (i >= 0) {
	//		while (i >= 0 && s[i] != ' ') {
	//			i--;
	//		}
	//		ret.append(s.substr(i + 1, j - i)).append(" ");
	//		while (i >= 0 && s[i] == ' ') {
	//			i--;
	//		}
	//		j = i;
	//	}
	//	return trim(ret);
	//}

	string reverseWords(string s) {
		int i = 0, n = s.size();
		string tmp, ans;
		while (i < n) {
			while (s[i] == ' ') {
				i++;
			}
			if (i == n) {
				break;
			}
			tmp = "";
			while (s[i] != ' ' && i < n) {
				tmp += s[i];
				++i;
			}
			ans = tmp + " " + ans;
		}
		if (!ans.empty()) {
			ans.pop_back();
		}
		return ans;
	}
};

int main() {
	Solution *solution = new Solution();
	//cout << solution->reverseWords("the sky is blue");
	//vector< std::string > ret = {};
	//solution->split("the sky is blue", " ", ret);
	string s = "  hello world!  ";
	cout << solution->reverseWords(s);
	return 0;
}