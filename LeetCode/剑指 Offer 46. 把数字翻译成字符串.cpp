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
		//��ȡ�������ֵ�������Ȼ��ݹ�ļ��㷭�뷽��
		int ba = num % 100;
		//���С�ڵ���9���ߴ��ڵ���26��ʱ���������ܰ���2λ������ϣ�����56��ֻ�ܲ��Ϊ5��6������25�����Բ��Ϊ2��5��Ҳ������Ϊ25һ��������з��롣
		if (ba <= 9 || ba >= 26) { 
			return translateNum(num / 10);
		}
		// ba=[10, 25]ʱ���ȿ��Ե���һ����ĸ��Ҳ���Ե���������ĸ
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