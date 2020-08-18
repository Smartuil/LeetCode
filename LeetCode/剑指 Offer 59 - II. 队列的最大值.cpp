#include "iostream"
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

//class MaxQueue {
//public:
//	MaxQueue() {
//		maxValue = INT_MIN;
//		while (!q.empty()) {
//			q.pop();
//		}
//		if (vec.size() != 0) {
//			vec.clear();
//		}
//	}
//
//	int max_value() {	
//		if (!q.empty()) {
//			return maxValue;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//
//	void push_back(int value) {
//		q.push(value);
//		if (value > maxValue) {
//			maxValue = value;			
//		}
//		vec.insert({ value,maxValue });
//	}
//
//	int pop_front() {
//		if (!q.empty()) {
//			int tmp = q.front();
//			q.pop();
//			maxValue = vec[tmp];
//			return tmp;
//		}
//		else
//		{
//			return -1;
//		}
//	}
//	queue<int> q;
//	int maxValue;
//	unordered_map<int, int> vec;
//};

//class MaxQueue {
//	queue<int> q;
//	deque<int> d;
//public:
//	MaxQueue() {
//	}
//
//	int max_value() {
//		if (d.empty())
//			return -1;
//		return d.front();
//	}
//
//	void push_back(int value) {
//		while (!d.empty() && d.back() < value) {
//			d.pop_back();
//		}
//		d.push_back(value);
//		q.push(value);
//	}
//
//	int pop_front() {
//		if (q.empty())
//			return -1;
//		int ans = q.front();
//		if (ans == d.front()) {
//			d.pop_front();
//		}
//		q.pop();
//		return ans;
//	}
//};

class MaxQueue {
public:
	MaxQueue() {

	}

	int max_value() {
		if (d.empty()) {
			return -1;
		}
		return d.front();
	}

	void push_back(int value) {
		while (!d.empty() && d.back() < value) {
			d.pop_back();
		}
		d.push_back(value);
		q.push(value);
	}

	int pop_front() {
		if (q.empty()) {
			return -1;
		}
		int tmp = q.front();
		if (tmp == d.front()) {
			d.pop_front();
		}
		q.pop();
		return tmp;
	}
	queue<int> q;
	deque<int> d;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

int main() {
	MaxQueue* obj = new MaxQueue();
	int param_1 = obj->max_value();
	obj->push_back(1);
	obj->push_back(-3);	
	obj->push_back(4);
	obj->push_back(10);
	int param_3 = obj->pop_front();
	int param_2 = obj->max_value();
	return 0;
}