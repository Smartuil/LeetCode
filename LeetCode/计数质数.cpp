#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isPrim(n, true);
		for (int i = 2; i * i < n; i++)
			if (isPrim[i])
				for (int j = i * i; j < n; j += i)
					isPrim[j] = false;

		int count = 0;
		for (int i = 2; i < n; i++)
			if (isPrim[i]) count++;

		return count;
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->countPrimes(15);
	return 0;
}