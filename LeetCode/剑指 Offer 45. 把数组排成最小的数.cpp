#include "iostream"
#include "vector"
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	string minNumber(vector<int>& nums) {
		vector<string> strs;
		string res;
		for (auto num : nums)
			strs.push_back(to_string(num));
		sort(strs.begin(), strs.end(), compare);
		//比如比较30和3，显然303比330小，所以30应该在前边，所以30<3 比较3和34，显然334<343,所以3应该在前边，3<34
		for (auto str : strs)
			res += str;
		return res;
	}
private:
	static bool compare(const string &a, const string &b)
	{
		return a + b < b + a;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 3,30,34,5,9 };
	cout << solution->minNumber(nums);
	return 0;
}