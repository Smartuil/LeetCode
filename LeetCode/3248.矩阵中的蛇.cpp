#include "iostream"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int finalPositionOfSnake(int n, vector<string>& commands) {
		int i = 0, j = 0;

		for (string s : commands)
		{
			if (s == "DOWN")
			{
				i += 1;
			}
			else if (s == "UP")
			{
				i -= 1;
			}
			else if (s == "RIGHT")
			{
				j += 1;
			}
			else if (s == "LEFT")
			{
				j -= 1;
			}
		}

		return (i * n) + j;
	}

};

int main()
{
	Solution* solution = new Solution();
	vector<string> commands = { "RIGHT","DOWN" };
	cout << solution->finalPositionOfSnake(2, commands) << endl;

	return 0;
}