#include "iostream"
#include "string"

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string result = "1";
		for (int i = 0; i < n - 1; ++i) {
			result = iter(result);
		}
		return result;
	}

	string iter(string s) {
		int num = 1;
		string res;
		for (int i = 0; i < s.size() - 1; ++i) {
			if (s[i] == s[i + 1])
				num++;
			else {
				res += num + '0';
				res += s[i];
				num = 1;
			}
		}
		res += num + '0';//此处要加上最后一个子序列的描述
		res += s[s.size() - 1];
		return res;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->countAndSay(3);
	return 0;
}