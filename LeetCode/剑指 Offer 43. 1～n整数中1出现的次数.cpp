#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	//int Count(int n)
	//{
	//	int i;

	//	if (n == 0)
	//	{
	//		i = 1;
	//	}

	//	for (i = 0; n != 0; i++)
	//	{
	//		n /= 10;
	//	}
	//	return i;
	//}

	int countDigitOne2(int n) {
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

	//https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/c-cong-ge-wei-bian-li-dao-zui-gao-wei-yi-ci-qiu-ji/
	int countDigitOne(int n) {
		int count = 0;
		long i = 1;//指向遍历的位数，如i=1即个位，i=10即十位，...，因为n可以有31位，所以10^31用long存储
		while (n / i != 0) {
			int high = n / (i * 10);
			int cur = (n / i) % 10;
			int low = n - (n / i)*i;
			if (cur == 0) {
				count += high * i;
			}
			else if (cur == 1) {
				count += high * i + 1 + low;
			}
			else
			{
				count += high * i + i;
			}
			i *= 10;
		}
		return count;
	}

};

int main() {
	Solution *solution = new Solution();
	cout << solution->countDigitOne(1112);
	return 0;
}