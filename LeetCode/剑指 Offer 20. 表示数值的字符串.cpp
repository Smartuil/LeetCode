#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//class Solution {
//public:
//	bool isNumber(string s) {
//		vector<map<char, int>> states;
//		map<char, int> temp;
//		// s代表sign，正负号
//		// d代表digit，数字
//
//		// 所有表之外的状态转移即为非法数字
//
//		// 0，头部空格状态
//		temp[' '] = 0;  // 输入 空格 还是 空格状态0
//		temp['s'] = 1;  // 输入 正负号 进入 符号状态1
//		temp['d'] = 2;  // 输入 数字 进入 小数点前数字状态2
//		temp['.'] = 4;	// 输入 小数点 进入 前为空小数点后首位数字状态4
//		states.push_back(temp);
//		temp.clear();
//		// 1，符号状态
//		temp['d'] = 2;  // 输入 数字 进入 小数点前的数字状态2
//		temp['.'] = 4;  // 输入小数点 进入 前为空小数点后首位数字状态4
//		states.push_back(temp);
//		temp.clear();
//		// 2，小数点前数字状态
//		temp['d'] = 2;  // 输入 数字 还是 小数点前的数字状态2
//		temp['.'] = 3;  // 输入 小数点 进入 前非空小数点后的数字状态3
//		temp['e'] = 5;	// 输入 e 进入 指数符号状态5
//		temp[' '] = 8;	// 输入 空格 进入 尾部空格状态8
//		states.push_back(temp);
//		temp.clear();
//		// 3，前非空小数点后的数字状态
//		temp['d'] = 3;	// 输入 数字 还是 前非空小数点后的数字状态3
//		temp['e'] = 5;	// 输入 e 进入 指数符号状态5
//		temp[' '] = 8; 	// 输入 空格 进入尾部空格状态8
//		states.push_back(temp);
//		temp.clear();
//		// 4，前为空小数点后首位数字状态4
//		temp['d'] = 3; 	// 输入 数字 进入 前非空小数点后的数字状态3
//		states.push_back(temp);
//		temp.clear();
//		// 5，指数符号状态5
//		temp['s'] = 6;  // 输入 正负号 进入 指数后的符号状态6
//		temp['d'] = 7;	// 输入 数字 进入 指数位置数字状态7
//		states.push_back(temp);
//		temp.clear();
//		// 6，指数后的符号状态
//		temp['d'] = 7;  // 输入 数字 进入 指数位置数字状态7
//		states.push_back(temp);
//		temp.clear();
//		// 7，指数位置数字状态
//		temp['d'] = 7;  // 输入 数字 还是 指数位置数字状态7
//		temp[' '] = 8;  // 输入 空格 进入 尾部空格状态8
//		states.push_back(temp);
//		temp.clear();
//		// 8，尾部空格状态
//		temp[' '] = 8;  // 输入 空格 还是 尾部空格状态8
//		states.push_back(temp);
//		temp.clear();
//
//		// 初始状态，在0状态
//		int p = 0;
//		// 状态转移的输入key
//		char t;
//		// 逐字符
//		for (int i = 0; i < s.length(); i++) {
//			char c = s[i];
//			// 如果是数字，key='d'
//			if (c >= '0'&&c <= '9') {
//				t = 'd';
//			}
//			// 如果是正负号，key='s'
//			else if (c == '+' || c == '-') {
//				t = 's';
//			}
//			// 如果是其他字符，key='c'，包含了'.' ' ' 其他非法字符
//			else {
//				t = c;
//			}
//			map<char, int>::iterator it = states[p].find(t);
//			// 如果找不到这个状态转移，则非法数字
//			if (it == states[p].end()) {
//				return false;
//			}
//			// 如果找到，获取转移后的状态
//			p = (int)it->second;
//		}
//		// 是否在允许结尾的状态2 3 7 8
//		return p == 2 || p == 3 || p == 7 || p == 8;
//	}
//};

class Solution {
public:
	using sIter = string::iterator;//typedef
	sIter sEnd;

	bool scanNumber(sIter& iter) {//找数字，找不到返回false
		bool have_number = false;
		while (iter != sEnd && (*iter) >= '0' && (*iter) <= '9') {
			have_number = true;
			iter++;
		}
		return have_number;
	}

	bool scanInteger(sIter& iter) {//找数字，找不到返回false(首位可为+或-)
		if (*iter == '+' || *iter == '-') iter++;
		return scanNumber(iter);
	}

	bool isNumber(string s) {
		if (s.empty()) return false;
		sIter iter = s.begin();
		sEnd = s.end();
		while (*iter == ' ') iter++;//去空格
		bool result = scanInteger(iter);//找A整数位
		if (*iter == '.') {//存在小数点，则找B小数位
			iter++;
			result |= scanNumber(iter);//小数位和整数位存在一个即可
		}
		if (*iter == 'e') {//存在e，则找指数位
			iter++;
			result = result && scanInteger(iter);//若有e，指数位C必须存在

		}
		if(iter!=sEnd)
			while (*iter == ' ') iter++;//去空格
		return result && iter == s.end();//若到达结尾且满足之前规则，返回true
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->isNumber("1.2.3");
	return 0;
}