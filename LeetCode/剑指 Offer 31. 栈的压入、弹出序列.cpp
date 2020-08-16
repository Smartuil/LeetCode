#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
#include <stack>
using namespace std;

class Solution {
public:

	//bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	//	stack<int> s;
	//	int i = 0;
	//	//while(i < pushed.size()) {
	//	//	while(j < popped.size()) {
	//	//		if (pushed[i] != popped[j]) {
	//	//			s.push(pushed[i]);
	//	//			i++;
	//	//		}
	//	//		else if(pushed[++i] == popped[++j])
	//	//		{
	//	//			j++;
	//	//		}
	//	//		else if(s.top() == popped[j])
	//	//		{
	//	//			j++;
	//	//			s.pop();
	//	//		}
	//	//	}
	//	//}
	//	for (auto j : pushed) {
	//		s.push(j);
	//		while (!s.empty() && s.top() == popped[i]) {
	//			s.pop();
	//			i++;
	//		}
	//	}
	//	return s.empty();
	//}

	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> s;
		int j = 0;
		for (auto i : pushed) {
			s.push(i);
			while (!s.empty() && s.top() == popped[j]) {
				s.pop();
				++j;
			}
		}
		return s.empty();
	}
};

int main() {
	Solution *solution = new Solution;
	vector<int> pushed = { 1,2,3,4,5 };
	vector<int> popped = { 4,5,3,2,1 };
	cout << solution->validateStackSequences(pushed, popped);

	return 0;
}