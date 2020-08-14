#include "iostream"
#include "string"
#include "vector"
#include <stack>
using namespace std;

class CQueue {
public:
	//stack<int> s1, s2;

	//CQueue() {
	//	while (!s1.empty()) {
	//		s1.pop();
	//	}
	//	while (!s2.empty()) {
	//		s2.pop();
	//	}
	//}

	//void appendTail(int value) {
	//	s1.push(value);
	//}

	//int deleteHead() {
	//	if (s2.empty()) {
	//		while (!s1.empty())
	//		{
	//			s2.push(s1.top());
	//			s1.pop();
	//		}
	//	}
	//	if (s2.empty()) {
	//		return -1;
	//	}
	//	else
	//	{
	//		int deleteItem = s2.top();
	//		s2.pop();
	//		return deleteItem;
	//	}
	//}

	stack<int> s1, s2;

	CQueue() {
		while (!s1.empty()) {
			s1.pop();
		}
		while (!s2.empty()) {
			s2.pop();
		}
	}

	void appendTail(int value) {
		s1.push(value);
	}

	int deleteHead() {
		if (s2.empty()) {
			while (!s1.empty()) {
				int tmp = s1.top();
				s1.pop();
				s2.push(tmp);
			}
		}
		if (!s2.empty()) {
			int tmp = s2.top();
			s2.pop();
			return tmp;
		}
		else
		{
			return -1;
		}
	}
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main() {
	CQueue* obj = new CQueue();
	vector<string> name = { "CQueue","appendTail","deleteHead","deleteHead" };
	vector<vector<int>> value = { {},{3},{},{} };

	return 0;
}