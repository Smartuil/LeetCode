#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include <stack>
using namespace std;

class MinStack {
public:
	//��Сջ 
	// stack�д��pair<int,int> firstΪval secondΪmin_val
	stack<pair<int, int>> min_stack;
	int min_val;
	MinStack() {
		min_val = INT_MAX;
	}
	void push(int x) {
		//ά����Сֵmin_val���� ����stack
		if (x <= min_val) {
			min_val = x;
		}
		min_stack.push({ x,min_val });
	}

	void pop() {
		//�ǿ�ɾ�� 
		//ά�� min_val����
		//ɾ����Ϊ�� min_valΪ��ʼ�� INT_MAX
		//ɾ����ǿ� min_valΪջ��second

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
		//ջ��firstΪval
		return min_stack.top().first;
	}

	int min() {
		//ջ��secondΪmin_val
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
	minStack->min();   //-- > ���� - 3.
	minStack->pop();
	minStack->top();   //-- > ���� 0.
	minStack->min();   //-- > ���� - 2.

	return 0;
}