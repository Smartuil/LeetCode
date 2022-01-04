#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int num = 0;
        for (int i = 1; i <= n; i++)
        {
            ret.push_back("Push");


            if (target[num] == i)
            {
                num++;
                if (num >= target.size())
                {
                    return ret;
                }
            }
            else
            {
                ret.push_back("Pop");
            }
        }
        return ret;
    }
};

int main()
{
    Solution* solution = new Solution();
    vector<int> nums = { 2, 3, 4 };
    auto ret = solution->buildArray(nums, 4);
    for (auto& tmp : ret)
    {
        cout << tmp << endl;
    }
    return 0;
}