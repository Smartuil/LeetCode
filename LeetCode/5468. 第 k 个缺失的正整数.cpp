#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int count = 0;
		int ret = 0;
		int pre = 0;
		set<int> s;
		for (int i = 0; i < arr.size(); i++) {
			int tmp = arr[i] - i - 1;
			if (tmp != count) {
				count++;
				int j = 1;
				if (i != 0) {
					j = arr[i - 1] + 1;
				}
				for (j; j < arr[i]; j++) {
					if(j!=arr[i])
						s.insert(j);
				}
			}
		}
		if (s.size() < k) {
			ret = arr.back() + k - s.size();
		}
		count = 0;
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			if (count == k-1) {
				return *iter;
			}
			count++;
		}
		
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> arr = { 1,13,18 };
	cout << solution->findKthPositive(arr, 17);
	return 0;
}