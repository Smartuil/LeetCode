#include "iostream"
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	//int maxProfit(vector<int>& prices) {
	//	int cost = INT_MAX, profit = 0;
	//	for (int price : prices) {
	//		cost = min(cost, price);
	//		profit = max(profit, price - cost);
	//	}
	//	return profit;
	//}

	int maxProfit(vector<int>& prices) {
		priority_queue<int, vector<int>, greater<int> > q;
		int ret = 0;
		for (int price : prices) {
			q.push(price);
			ret = max(ret, price - q.top());
		}
		return ret;
	}

};

int main() {
	Solution* solution = new Solution();
	vector<int> prices = { 7,1,5,3,6,4 };
	cout << solution->maxProfit(prices);
	return 0;
}