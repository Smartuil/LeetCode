#include "iostream"
#include "vector"
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
	set<string> result;
	void func(string s, int start, int end)
	{
		if (start == end)
			result.insert(s);
		else
		{
			for (int i = start; i <= end; i++)
			{
				swap(s[i], s[start]);
				func(s, start + 1, end);
				swap(s[i], s[start]);
			}
		}
	}

	vector<string> permutation(string s) {
		vector<string> results;
		if (s.size() == 0) {
			return {};
		}
		else if(s.size() == 1)
		{
			return { s };
		}
		else
		{
			func(s, 0, s.size() - 1);
			for (auto i : result) {
				results.push_back(i);
			}
			return results;
		}
	}
};

int main() {
	Solution *solution = new Solution();

	vector<string> ret = solution->permutation("aab");
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}