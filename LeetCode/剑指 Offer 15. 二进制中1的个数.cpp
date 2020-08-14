#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	//int hammingWeight(uint32_t n) {
	//	int ret = 0;
	//	while (n) {
	//		if (n & 1) {
	//			ret++;
	//		}
	//		n = n >> 1;
	//	}
	//	
	//	return ret;
	//}
	int hammingWeight(uint32_t n) {
		int ret = 0;
		while (n) {
			if (n % 2 == 1) {
				ret++;
			}
			n /= 2;
		}

		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->hammingWeight(00000000000000000000000000001011);
	return 0;
}