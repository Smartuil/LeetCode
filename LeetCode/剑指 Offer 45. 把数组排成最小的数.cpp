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
		////����Ƚ�30��3����Ȼ303��330С������30Ӧ����ǰ�ߣ�����30<3 �Ƚ�3��34����Ȼ334<343,����3Ӧ����ǰ�ߣ�3<34
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
		return a + b < b + a;//�밴ʲô��������򣬾�����������·��ص�ֵ��true�������������ƺ�������>=����<=�����ķ���
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 3,30,34,5,9 };
	cout << solution->minNumber(nums);
	return 0;
}