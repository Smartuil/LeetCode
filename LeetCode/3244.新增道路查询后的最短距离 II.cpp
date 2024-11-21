#include "iostream"
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		vector<int> roads(n);
		iota(roads.begin(), roads.end(), 1);
		vector<int> res;
		int dist = n - 1;
		for (auto& query : queries) {
			int k = roads[query[0]];
			while (k != -1 && k < query[1]) {
				if (k < query[1]) {
					roads[query[0]] = query[1];
				}
				int t = roads[k];
				roads[k] = -1;
				k = t;
				dist--;
			}
			res.push_back(dist);
		}
		return res;
	}
};

int main()
{
	Solution* solution = new Solution();
	vector<vector<int>> queries = { {2, 4}, {0, 2}, {0, 4} };

	for (int& item : solution->shortestDistanceAfterQueries(5, queries))
	{
		cout << item << endl;
	}

	return 0;
}