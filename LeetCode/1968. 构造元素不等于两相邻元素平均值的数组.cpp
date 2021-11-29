#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = (n + 1) / 2;
        vector<int> res;
        for (int i = 0; i < m; ++i)
        {
            res.push_back(nums[i]);
            if (i + m < n)
            {
                res.push_back(nums[i + m]);
            }
        }
        return res;
    }
};

int main()
{
    Solution* solution = new Solution();
    vector<int> arr = { 6,2,0,9,7};
    auto ret = solution->rearrangeArray(arr);
    for (auto& tmp : ret)
    {
        cout << tmp << endl;
    }

    return 0;
}