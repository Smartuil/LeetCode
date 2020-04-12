#include "iostream"
#include "vector"
using namespace std;

//class Solution {
//public:
//	int weishu[10] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
//	int max = 0x7fffffff;
//	int reverse(int x) {
//		vector<int> ret;
//		double rev_num = 0;
//		while (1) {
//			ret.push_back(x % 10);
//			x = x / 10;
//			if (x == 0) {
//				break;
//			}
//		}
//		int j;
//		for (int i = ret.size() - 1, j = 0; i >= 0; i--, j++) {
//			rev_num += ret[i] * weishu[j];
//		}
//		return rev_num > max || rev_num < (-1 * (max + 1)) ? 0 : rev_num;
//	}
//};

class Solution {
public:
	int reverse(int x) {
		int max = 0x7fffffff;
		long b = 0;
		while (x != 0) {
			b = b * 10 + x % 10;
			x = x / 10;
		}
		return (b > max || b < (-1 * (max + 1))) ? 0 : b;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->reverse(1534236469);
	return 0;
}