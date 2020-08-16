#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include <stack>
#include <map>
#include <unordered_map>
using namespace std;

//class MinStack {
//public:
//	//��Сջ 
//	// stack�д��pair<int,int> firstΪval secondΪmin_val
//	stack<pair<int, int>> min_stack;
//	int min_val;
//	MinStack() {
//		min_val = INT_MAX;
//	}
//	void push(int x) {
//		//ά����Сֵmin_val���� ����stack
//		if (x <= min_val) {
//			min_val = x;
//		}
//		min_stack.push({ x,min_val });
//	}
//
//	void pop() {
//		//�ǿ�ɾ�� 
//		//ά�� min_val����
//		//ɾ����Ϊ�� min_valΪ��ʼ�� INT_MAX
//		//ɾ����ǿ� min_valΪջ��second
//
//		if (!min_stack.empty()) {
//			min_stack.pop();
//		}
//		if (min_stack.empty()) {
//			min_val = INT_MAX;
//		}
//		else {
//			min_val = min_stack.top().second;
//		}
//
//	}
//
//	int top() {
//		//ջ��firstΪval
//		return min_stack.top().first;
//	}
//
//	int min() {
//		//ջ��secondΪmin_val
//		return min_stack.top().second;
//	}
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {
		while (!s.empty()) {
			s.pop();
		}
		minVal = INT_MAX;
	}

	void push(int x) {
		if (x <= minVal) {
			minVal = x;
		}
		s.push({ x,minVal });
	}

	void pop() {
		if (!s.empty()) {		
			s.pop();
		}
		if (s.empty()) {
			minVal = INT_MAX;
		}
		else
		{
			minVal = s.top().second;
		}	
	}

	int top() {
		return s.top().first;
	}

	int min() {
		return minVal;
	}
private:
	int minVal;
	stack < pair<int, int> > s;
};

int main() {
	MinStack *minStack = new MinStack();
	minStack->push(2147483646);
	minStack->push(2147483646);
	minStack->push(2147483647);
	minStack->top();
	minStack->pop();
	minStack->min();
	minStack->pop();
	minStack->min();
	minStack->pop();
	minStack->push(2147483647);
	minStack->top();

	minStack->min();
	minStack->push(2147483648);
	minStack->top();
	minStack->min();
	minStack->pop();
	minStack->min(); 
	return 0;
}