#include "iostream"
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	//int sumNums(int n) {
	//	n && (n += sumNums(n - 1));
	//	return n;
	//}

	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return 0;
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->sumNums(3);
	return 0;
}