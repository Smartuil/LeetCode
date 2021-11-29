#include "iostream"
#include "vector"
#include "algorithm"
#include <queue>

using namespace std;

//class Solution {
//public:
//    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//        int n = arr.size();
//        vector<pair<int, int>> frac;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                frac.emplace_back(arr[i], arr[j]);
//            }
//        }
//        sort(frac.begin(), frac.end(), [&](const auto& x, const auto& y) {
//            return x.first * y.second < x.second* y.first;
//            });
//        return { frac[k - 1].first, frac[k - 1].second };
//    }
//};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        auto cmp = [&](const pair<int, int>& x, const pair<int, int>& y) {
            return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int j = 1; j < n; ++j) {
            q.emplace(0, j);
        }
        while(k-- > 1) {
            auto tmp = q.top();
            q.pop();
            int i = tmp.first;
            int j = tmp.second;
            if (i + 1 < j) {
                q.emplace(i + 1, j);
            }
        }
        return { arr[q.top().first], arr[q.top().second] };
    }
};

int main()
{
	Solution* solution = new Solution();
	vector<int> arr = {1, 2, 3, 5};
	auto ret = solution->kthSmallestPrimeFraction(arr, 3);
	for (auto& tmp : ret)
	{
		cout << tmp << endl;
	}

	return 0;
}