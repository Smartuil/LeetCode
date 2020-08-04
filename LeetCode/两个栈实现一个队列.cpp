#include "iostream"
#include "stack"

using namespace std;

class Solution {
public:
	Solution() {
		if (!s1.empty()) {
			s1.pop();
		}

		if (!s2.empty()) {
			s2.pop();
		}
	}

	int dequeue() {
		if (s2.empty()) {
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		if (s2.empty()) {
			return -1;
		}
		else
		{
			int deleteItem = s2.top();
			s2.pop();
			return deleteItem;
		}
	}

	void inqueue(int val) {
		s1.push(val);
	}
private:
	stack<int> s1;
	stack<int> s2;
};

int main() {
	Solution *solution = new Solution();

}
