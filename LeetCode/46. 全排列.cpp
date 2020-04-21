#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
	//vector<vector<int> > result;
	//void func(vector<int> &nums, vector<int> &current, vector<bool>&nums1)
	//{
	//	if (current.size() == nums1.size())
	//		result.push_back(current);
	//	else
	//	{
	//		for (int i = 0; i < nums.size(); i++)
	//		{
	//			if (nums1[i])
	//			{
	//				current.push_back(nums[i]);
	//				nums1[i] = false;
	//				func(nums, current, nums1);
	//				nums1[i] = true;
	//				current.pop_back();
	//			}
	//		}
	//	}
	//}
	//vector<vector<int>> permute(vector<int>& nums) {
	//	if (nums.size() == 0) {
	//		return {};
	//	}	
	//	else if (nums.size() == 1) {
	//		return { {nums[0]} };
	//	}
	//	else
	//	{
	//		vector<bool> nums1(nums.size(), true);
	//		vector<int> current;
	//		func(nums, current, nums1);
	//		return result;
	//	}
	//}


	vector<vector<int> > result;
	void func(vector<int> &nums, int start, int end)
	{
		if (start == end)
			result.push_back(nums);
		else
		{
			for (int i = start; i <= end; i++)
			{
				swap(nums[i], nums[start]);
				func(nums, start + 1, end);
				swap(nums[i], nums[start]);
			}
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0)
			return {};
		else if (nums.size() == 1)
			return { {nums[0]} };
		else
		{
			func(nums, 0, nums.size() - 1);
			return result;
		}
	}

};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> ret = solution->permute(nums);
	cout << "[" << endl;
	for (auto i : ret) {
		cout << "[";
		for (auto j : i) {
			cout << j;
		}
		cout << "]" << endl;
	}
	cout << "]";
	return 0;
}