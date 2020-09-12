#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
#include <stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		minNum = INT_MAX;
	}

	void push(int x) {
		if (x < minNum) {
			minNum = x;
		}
		s.push({ x, minNum });
	}

	void pop() {
		if (!s.empty()) {
			s.pop();
			if (s.empty()) {
				minNum = INT_MAX;
			}
			else
			{
				minNum = s.top().second;
			}
		}
	}

	int top() {
		return s.top().first;
	}

	int getMin() {
		return minNum;
	}
private:
	stack<pair<int, int>> s;
	int minNum;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
	vector<int> nums = { 1,2,3 };
	MinStack* obj = new MinStack();
	obj->push(1);
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();
	return 0;
}