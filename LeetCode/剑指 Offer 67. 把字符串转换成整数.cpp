#include "iostream"
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	//int strToInt(string str) {
	//	int res = 0;
	//	int bndry = INT_MAX / 10;
	//	int i = 0;
	//	int sign = 1;
	//	int len = str.size();
	//	if (len == 0) {
	//		return 0;
	//	}
	//	while (str[i] == ' ') {
	//		if (++i == len) {
	//			return 0;
	//		}
	//	}
	//	if (str[i] == '-') {
	//		sign = -1;
	//	}
	//	if (str[i] == '-' || str[i] == '+') {
	//		i++;
	//	}
	//	for (int j = i; j < len; ++j) {
	//		if (str[j]<'0' || str[j]>'9') {
	//			break;
	//		}
	//		if (res > bndry || res == bndry && str[j] > '7') {
	//			return sign == 1 ? INT_MAX : INT_MIN;
	//		}
	//		res = res * 10 + (str[j] - '0');
	//	}
	//	return sign * res;
	//}

	int strToInt(string str) {
		int sign = 1;
		int ret = 0;
		int i = 0;
		if (str.size() == 0) {
			return 0;
		}
		while (str[i] == ' ') {
			if (i == str.size()) {
				return 0;
			}
			i++;
		}
		if (str[i] == '-') {
			sign = -1;
		}
		if (str[i] == '-' || str[i] == '+') {
			++i;
		}
		if (str[i]<'0'&&str[i]>'9') {
			return 0;
		}
		while (str[i]>='0'&&str[i]<='9') {
			
			if (ret > 214748364 || (ret == 214748364 && str[i] > '7')) {
				return sign == 1 ? INT_MAX : INT_MIN;
			}
			ret = ret * 10 + (str[i] - '0');
			++i;
		}
		return sign * ret;
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->strToInt("   -123");
	return 0;
}