#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
	//string minNumber(vector<int>& nums) {
		//vector<string> strs;
		//string res;
		//for (auto num : nums)
		//	strs.push_back(to_string(num));
		//sort(strs.begin(), strs.end(), compare);
		////比如比较30和3，显然303比330小，所以30应该在前边，所以30<3 比较3和34，显然334<343,所以3应该在前边，3<34
		//for (auto str : strs)
		//	res += str;
		//return res;
	//}
	priority_queue<int/*, vector<int>, greater<int>*/ > q;
	string minNumber(vector<int>& nums) {
		vector<string> strs;
		string res;
		for (auto num : nums) {
			strs.push_back(to_string(num));
			//q.push(num);
		}
		sort(strs.begin(), strs.end(), compare);
		for (auto s : strs) {
			res += s;
		}
		return res;
	}
private:
	static bool compare(const string &a, const string &b)
	{
		return a + b < b + a;//想按什么情况来排序，就是这种情况下返回的值是true，但是这里面似乎不能用>=或者<=这样的符号
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 3,30,34,5,9 };
	cout << solution->minNumber(nums);
	return 0;
}