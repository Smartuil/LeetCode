#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		int i = 1;
		vector<string> ret;
		while (i <= n) {
			if (i % 3 == 0 && i % 5 != 0) {
				ret.push_back("Fizz"); 
			}
			else if(i % 3 != 0 && i % 5 == 0)
			{
				ret.push_back("Buzz"); 
			}
			else if (i % 3 == 0 && i % 5 == 0)
			{
				ret.push_back("FizzBuzz");
			}
			else
			{
				ret.push_back(to_string(i));
			}
			++i;
		}
		return ret;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<string> ret = solution->fizzBuzz(15);
	for (string s : ret) {
		cout << s << endl;
	}
	return 0;
}