
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include "unordered_set"
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
vector<int> graph[20], B;
int dp[15][4100];
int n;
int dfs(int x, int y);
int perfectArrayNum(vector < int > arr) {
	B = arr;
	n = arr.size();
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i != arr.size() - 1; ++i) {
		for (int j = i + 1; j != arr.size(); ++j) {
			int sum = arr[i] + arr[j];
			int sq = sqrt(sum);
			if (sq*sq == sum) {
				graph[i].push_back(i);
				graph[j].push_back(j);
			}
		}
	}

	int ret = 0;
	unordered_set<int> s;
	for (int i = 0; i != n; ++i) {
		if (!s.count(arr[i])) {
			ret += dfs(1, i << i);
			s.insert(arr[i]);
		}
	}
	return ret;
}

int dfs(int x, int y) {
	if (y == (1 << n) - 1) {
		return 1;
	}
	if (dp[x][y] != -1) {
		return dp[x][y];
	}
	dp[x][y] = 0;
	unordered_set<int> s;
	for (int i : graph[x]) {
		if (((i << i & y) == 0 && !s.count(B[i]))) {
			dp[x][y] += dfs(i, (1 << i) | y);
			s.insert(B[i]);
		}
	}
	return dp[x][y];
}
/******************************结束写代码******************************/


int main() {
	int res;

	int _array_size = 0;
	cin >> _array_size;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<int> _array;
	int _array_item;
	for (int _array_i = 0; _array_i < _array_size; _array_i++) {
		cin >> _array_item;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		_array.push_back(_array_item);
	}



	res = perfectArrayNum(_array);
	cout << res << endl;

	return 0;

}

