#include "iostream"
#include "string"
#include <sstream>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int len = str.size();
		string ret;
		double ret_d = 0;
		for (int i = 0; i < len; i++) {
			if (str[i] == ' ') {
				//if (i != 0) {
				//	
				//}
				if (!ret.empty()) {
					break;
				}
				continue;
			}
			else if ((str[i] < '0' || str[i] > '9') && (str[i] != '-' && str[i] != '+')) {
				if (i != 0) {
					break;
				}
				if (i == 0) {
					return 0;
				}
			}
			else
			{
				ret.push_back(str[i]);
			}
		}
		string2num(ret, ret_d);
		if (ret_d > 2147483647.0) {
			return 2147483647;
		}
		if (ret_d < -2147483648.0) {
			return -2147483648.0;
		}
		return ret_d;
	}

	void string2num(string str, double &num)
	{
		stringstream ss;
		ss << str;
		ss >> num;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->myAtoi("   -42");
	return 0;
}