#include "iostream"
#include "string"
#include "vector"
#include <Windows.h>
using namespace std;

class Solution {
public:
	string replaceSpace(string s) {
		string ret;
		int index = 0;
		while (s.size()) {
			index = s.find(" ");
			if (index == -1) {
				ret.append(s);
				break;
			}
			s.replace(s.find(" "), 1, "%20");
			index = s.find(" ");
			ret.append(s.substr(0, index));
			if(index!=-1)
				s = s.substr(index);
			else
			{
				break;
			}
		}

		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->replaceSpace("%20");
	return 0;
}