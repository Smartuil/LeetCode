#include "iostream"
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int cost = INT_MAX, profit = 0;
		for (int price : prices) {
			cost = min(cost, price);
			profit = max(profit, price - cost);
		}
		return profit;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> prices = { 7,1,5,3,6,4 };
	cout << solution->maxProfit(prices);
	return 0;
}