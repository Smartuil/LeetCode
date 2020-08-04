#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include <stack>
using namespace std;

class MinStack {
public:
	//最小栈 
	// stack中存放pair<int,int> first为val second为min_val
	stack<pair<int, int>> min_stack;
	int min_val;
	MinStack() {
		min_val = INT_MAX;
	}
	void push(int x) {
		//维护最小值min_val定义 插入stack
		if (x <= min_val) {
			min_val = x;
		}
		min_stack.push({ x,min_val });
	}

	void pop() {
		//非空删除 
		//维护 min_val定义
		//删除后为空 min_val为初始化 INT_MAX
		//删除后非空 min_val为栈顶second

		if (!min_stack.empty()) {
			min_stack.pop();
		}
		if (min_stack.empty()) {
			min_val = INT_MAX;
		}
		else {
			min_val = min_stack.top().second;
		}

	}

	int top() {
		//栈顶first为val
		return min_stack.top().first;
	}

	int min() {
		//栈顶second为min_val
		return min_stack.top().second;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main() {
	MinStack *minStack = new MinStack();
	minStack->push(-2);
	minStack->push(0);
	minStack->push(-3);
	minStack->min();   //-- > 返回 - 3.
	minStack->pop();
	minStack->top();   //-- > 返回 0.
	minStack->min();   //-- > 返回 - 2.

	return 0;
}