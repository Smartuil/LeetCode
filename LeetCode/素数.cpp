#include <iostream>
#include "vector"

using namespace std;

class Solution {
public:
	std::vector<int> find_prime(std::vector<int> nums) {
		std::vector<int> ret;
		for (auto i : nums) {
			if (isPrime(i)) {
				ret.push_back(i);
			}
		}
		return ret;
	}

	bool isPrime(int n) {
		int k = (int)sqrt((double)n);
		int i;
		for (i = 2; i <= k; i++)
			if (n%i == 0)
				break;
		if (i > k)
			return true;
		else
			return false;
	}
};




int main() {
	Solution *solution = new Solution();
	vector<int> a = { 3,5,11,12 };
	vector<int> ret = solution->find_prime(a);

	return 0;
}