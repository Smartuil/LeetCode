#include "iostream"
#include "algorithm"
#include "vector"
#include <stack>
using namespace std;
//https://blog.csdn.net/smileiam/article/details/88732245
vector<int> findMaxRight(vector<int> &arr) {
	if(arr.size() == 0) {
		return arr;
	}

	int arr_len = arr.size();
	vector<int> ret(arr_len);
	stack<int> s;
	s.push(0);
	int index = 1;
	while (index< arr_len)
	{
		if (!s.empty() && arr[index] > arr[s.top()]) {
			ret[s.top()] = arr[index];
			s.pop();
		}
		else
		{
			s.push(index);
			index++;
		}
	}
	while (!s.empty()) {
		ret[s.top()] = -1;
		s.pop();
	}
	return ret;
}

int main() {
	vector<int> a = { 8, 2, 5, 4, 3, 9, 7, 2, 5 };
	vector<int> ret = findMaxRight(a);
	for (auto i : ret) {
		cout << i << " ";
	}
	return 0;
}