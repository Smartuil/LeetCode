#include "iostream"
#include "string"
#include "vector"
#include <Windows.h>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		string ret;
		int index = 0;
		while (s.size()) {
			index = s.find(" ");
			if (index == -1) {
				ret.append(s);
				break;
			}
			s.replace(s.find(" "), 1, "%20");
			index = s.find(" ");
			ret.append(s.substr(0, index));
			if(index!=-1)
				s = s.substr(index);
			else
			{
				break;
			}
		}

		return ret;
	}
};

//class Solution {
//public:
//	string replaceSpace(string s) {     //字符数组
//		string array;   //存储结果
//
//		for (auto &c : s) {   //遍历原字符串
//			if (c == ' ') {
//				array.push_back('%');
//				array.push_back('2');
//				array.push_back('0');
//			}
//			else {
//				array.push_back(c);
//			}
//		}
//		return array;
//	}
//};

int main() {
	Solution *solution = new Solution();
	cout << solution->replaceSpace("%20");
	return 0;
}