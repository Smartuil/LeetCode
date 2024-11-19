#include "iostream"
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		vector<int> Ret;

		//vector<vector<int>>neighbors(n);
		//for (int i = 0; i < n - 1; i++)
		//{
		//	neighbors[i].push_back(i + 1);
		//}

		//for (auto& query : queries)
		//{
		//	neighbors[query[0]].push_back(query[1]);
		//	Ret.push_back(bfs(n, neighbors));
		//}

		vector<vector<int>> prev(n);
		vector<int> dp(n);
		for (int i = 1; i < n; i++) {
			prev[i].push_back(i - 1);
			dp[i] = i;
		}

		for (auto& query : queries) {
			prev[query[1]].push_back(query[0]);
			for (int v = query[1]; v < n; v++) {
				for (int u : prev[v]) {
					dp[v] = min(dp[v], dp[u] + 1);
				}
			}
			Ret.push_back(dp[n - 1]);
		}

		return Ret;
	}

	int bfs(int n, const vector<vector<int>>& neighbors)
	{
		vector<int> dist(n, -1);
		queue<int> q;
		q.push(0);
		dist[0] = 0;
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int y : neighbors[x])
			{
				if (dist[y] >= 0)
				{
					continue;
				}

				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}

		return dist[n - 1];
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