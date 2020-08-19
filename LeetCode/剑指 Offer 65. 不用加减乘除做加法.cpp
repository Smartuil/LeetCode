#include "iostream"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//int add(int a, int b) {
	//	while (b != 0) { // ����λΪ 0 ʱ����
	//		int c = (a & b) << 1;  // c = ��λ
	//		a ^= b; // a = �ǽ�λ��
	//		b = c; // b = ��λ
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