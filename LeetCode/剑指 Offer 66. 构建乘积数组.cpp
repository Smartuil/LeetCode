#include "iostream"
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		if (a.size() == 0) return { 0 };
		vector<int> b(a.size());
		b[0] = 1;
		int tmp = 1;
		for (int i = 1; i < a.size(); i++) {
			b[i] = b[i - 1] * a[i - 1];
		}
		for (int i = a.size() - 2; i >= 0; i--) {
			tmp *= a[i + 1];
			b[i] *= tmp;
		}
		return b;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> a = { 1,2,3,4,5 };
	vector<int> ret = solution->constructArr(a);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}