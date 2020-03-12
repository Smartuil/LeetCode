#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string ret;
		int i;
		//char roman[] = { 'I', 'IV','V','IX','X','XL','L', 'XC', 'C', 'CD', 'D', 'CM', 'M' };
		vector<string>  roman= { "I", "IV","V","IX","X","XL","L", "XC", "C", "CD", "D", "CM", "M" };
		int romanNum[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
		for (i = 0; i < 13; i++) {
			if (num >= romanNum[i]) {
				continue;
			}
			if(num<romanNum[i])
				break;
		}
		i--;
		while (i >= 0) {
			if (num - romanNum[i] >= 0) {
				ret.append(roman[i]);
				//ret.push_back(roman[i]);
				num -= romanNum[i];
			}
			else {
				i--;
			}
		}
		return ret;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->intToRoman(3);
	return 0;
}