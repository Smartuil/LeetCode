#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int profit = 0;
		int inNum = INT_MAX;
		for (int price : prices) {
			inNum = min(inNum, price);
			profit = max(price - inNum, profit);
		}
		return profit;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> prices = { 7,1,5,3,6,4 };
	cout << solution->maxProfit(prices);
	return 0;
}