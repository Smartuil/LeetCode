#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	int translateNum(int num) {
		if (num <= 9) { 
			return 1; 
		}
		//获取输入数字的余数，然后递归的计算翻译方法
		int ba = num % 100;
		//如果小于等于9或者大于等于26的时候，余数不能按照2位数字组合，比如56，只能拆分为5和6；反例25，可以拆分为2和5，也可以作为25一个整体进行翻译。
		if (ba <= 9 || ba >= 26) { 
			return translateNum(num / 10);
		}
		// ba=[10, 25]时，既可以当做一个字母，也可以当做两个字母
		else { 
			return translateNum(num / 10) + translateNum(num / 100);
		}

		//int a = 1, b = 1, x, y = num % 10;
		//while (num != 0) {
		//	num /= 10;
		//	x = num % 10;
		//	int tmp = 10 * x + y;
		//	int c = (tmp >= 10 && tmp <= 25) ? a + b : a;
		//	b = a;
		//	a = c;
		//	y = x;
		//}
		//return a;

		//string s = to_string(num);
		//int a = 1, b = 1;
		//for (int i = 2; i <= s.size(); ++i) {
		//	string tmp = s.substr(i - 2, 2);
		//	int c = tmp >= "10"&&tmp <= "25" ? a + b : a;
		//	b = a;
		//	a = c;
		//}
		//return a;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->translateNum(12258);
	return 0;
}