#include "iostream"
#include "string"
#include "vector"
#include<algorithm>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int ret = 0;
		int i = 0;
		vector<string>  roman = { "I", "IV","V","IX","X","XL","L", "XC", "C", "CD", "D", "CM", "M" };
		int romanNum[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
		while(i < s.size()) {
			if (s[i] == 'I') {
				if (s[i + 1] == 'V') {
					ret += 4;
					i += 2;
				}
				else if(s[i + 1] == 'X')
				{
					ret += 9;
					i += 2;
				}
				else {
					string tmp;
					tmp.clear();
					tmp.push_back(s[i]);
					ret += romanNum[findRoman(roman, tmp)];
					i++;
				}
			}
			else if(s[i] == 'X')
			{
				if (s[i + 1] == 'L') {
					ret += 40;
					i += 2;
				}
				else if (s[i + 1] == 'C')
				{
					ret += 90;
					i += 2;
				}
				else {
					string tmp;
					tmp.clear();
					tmp.push_back(s[i]);
					ret += romanNum[findRoman(roman, tmp)];
					i++;
				}
			}
			else if (s[i] == 'C')
			{
				if (s[i + 1] == 'D') {
					ret += 400;
					i += 2;
				}
				else if (s[i + 1] == 'M')
				{
					ret += 900;
					i += 2;
				}
				else {
					string tmp;
					tmp.clear();
					tmp.push_back(s[i]);
					ret += romanNum[findRoman(roman, tmp)];
					i++;
				}
			}
			else
			{	
				string tmp;
				tmp.clear();
				tmp.push_back(s[i]);
				ret += romanNum[findRoman(roman, tmp)];
				i++;
			}
		}
		return ret;
	}

	int findRoman(vector<string>  roman, string ss) {
		for (int i = 0; i < 13; i++) {
			if (ss == roman[i]) {
				return i;
			}
		}
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->romanToInt("III");
	return 0;
}