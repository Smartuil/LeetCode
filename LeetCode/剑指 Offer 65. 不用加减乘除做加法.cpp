#include "iostream"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//int add(int a, int b) {
	//	while (b != 0) { // 当进位为 0 时跳出
	//		int c = (a & b) << 1;  // c = 进位
	//		a ^= b; // a = 非进位和
	//		b = c; // b = 进位
	//	}
	//	return a;
	//}

	int add(int a, int b) {
		while (b != 0) {
			int c = (unsigned int)(a&b) << 1;
			a ^= b;
			b = c;
		}
		return a;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->add(1, 1);
	return 0;
}