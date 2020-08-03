#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string ret;
		int i = 0;
		int j = 0;
		int jinwei = 0;
		int sum = 0;
		if (num1.size() > num2.size()) {
			i = num1.size() - 1;
			j = num2.size() - 1;
		}
		else
		{
			j = num1.size() - 1;
			i = num2.size() - 1;
		}

		while (i >= 0 || j >= 0) {
			if (!(j >= 0)) {
				if (num1.size() > num2.size()) {
					sum = num1[i] + jinwei - '0';
					i--;
				}
				else
				{
					sum = num2[i] + jinwei - '0';
					i--;
				}
				
			}
			else
			{
				if (num1.size() > num2.size()) {
					sum = num1[i] + num2[j] + jinwei - '0' - '0';
					i--;
					j--;
				}
				else
				{
					sum = num2[i] + num1[j] + jinwei - '0' - '0';
					i--;
					j--;
				}
				
			}
			
			jinwei = sum / 10;
			sum = sum % 10;
			ret.push_back(sum+'0');
		}
		if (jinwei) {
			ret.push_back(jinwei + '0');
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->addStrings("98", "9");
	return 0;
}