#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	int Count(int n)
	{
		int i;

		if (n == 0)
		{
			i = 1;
		}

		for (i = 0; n != 0; i++)
		{
			n /= 10;
		}
		return i;
	}

	int countDigitOne(int n) {
		//int ret = 0;
		//int count = Count(n);
		//for (int i = n; i > 0; i--) {
		//	int tmp = i;
		//	int tmpCount = count;
		//	while (tmp) {	
		//		
		//		int chushu = pow(10, tmpCount - 1);
		//		int deshu = tmp / chushu;
		//		if (deshu == 1) {
		//			ret++;
		//		}
		//		tmp = tmp % chushu;
		//		tmpCount--;
		//	}


		//	if (i == pow(10, count - 1)) {
		//		count--;
		//	}
		//}

		//return ret;

		int digit = 1, res = 0;
		int high = n / 10, cur = n % 10, low = 0;
		while (high != 0 || cur != 0) {
			if (cur == 0) res += high * digit;
			else if (cur == 1) res += high * digit + low + 1;
			else res += (high + 1) * digit;
			low += cur * digit;
			cur = high % 10;
			high /= 10;
			digit *= 10;
		}
		return res;

	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->countDigitOne(1410065408);
	return 0;
}