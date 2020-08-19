#include "iostream"
#include <sstream>
#include "vector"
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
	//int lastRemaining(int n, int m) {
	//	int f = 0;
	//	for (int i = 2; i != n + 1; ++i)
	//		f = (m + f) % i;//(当前index + m) % 上一轮剩余数字的个数
	//	return f;
	//}

	int lastRemaining(int n, int m) {
		int ret = 0;
		for (int i = 2; i != n + 1; ++i) {
			ret = (ret + m) % i;
		}
		return ret;
	}
};

//class Solution {
//	int f(int n, int m) {
//		if (n == 1)
//			return 0;
//		int x = f(n - 1, m);
//		return (m + x) % n;
//	}
//public:
//	int lastRemaining(int n, int m) {
//		return f(n, m);
//	}

//};

int main() {
	Solution *solution = new Solution();
	cout << solution->lastRemaining(5, 3);
	return 0;
}