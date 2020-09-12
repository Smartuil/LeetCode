#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) return false;
		double a = log10(n) / log10(3);        //����
		return  a == floor(a);         //�жϻ��׺��log3n�Ƿ�Ϊ��������n�Ƿ�Ϊ3�ı���
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->isPowerOfThree(15);
	return 0;
}