#include "iostream"
#include "string"
#include "vector"
#include "cmath"

using namespace std;

//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		string ret;
//		int tmp = 0;
//		vector<char> first;
//		vector<vector<char>> second;
//		int jinwei = 0;
//		int jieguo = 0;
//		int gewei = 0;
//		if (num1[0] - '0'  == 0 || num2[0] - '0' == 0) {
//			return "0";
//		}
//		if (num1.size() < num2.size()) {
//			string t = num1;
//			num1 = num2;
//			num2 = t;
//		}
//
//		for (int i = num2.size() - 1; i >= 0; i--) {
//			first.clear();
//			int cha = i + 1 - num2.size();
//			int loopNum = abs(cha);
//			while (loopNum > 0) {
//				first.push_back('0');
//				loopNum--;
//			}
//			jinwei = 0;
//			for (int j = num1.size() - 1; j >= 0; j--) {
//				//int a = (num1[j] - '0');
//				//int b = (num2[i] - '0');
//				//int c = (num1[j] - '0') * (num2[i] - '0');
//				jieguo = (num1[j] - '0') * (num2[i] - '0') + jinwei;
//				gewei = jieguo % 10;
//				jinwei = (num1[j] - '0') * (num2[i] - '0') / 10;
//				//tmp = jieguo * pow(10,i) + tmp;
//				first.push_back((char)(gewei + '0'));
//				if (jinwei > 0 && j == 0) {
//					first.push_back((char)(jinwei + '0'));
//				}
//			}
//			//reverse(first.begin(), first.end());
//
//			second.push_back(first);
//		}
//
//		//second.clear();
//		//second.push_back({ '8','8','8','6' });
//		//second.push_back({ '0','0','2','9','9','9' });
//		vector<char> temp = second[0];
//		int jinwei2 = 0;
//		int deshu = 0;
//		int gewei2 = 0;
//		for (int i = 1; i < second.size(); i++) {
//			jinwei2 = 0;
//			for (int j = 0; j < second[i].size(); j++) {
//				if (second[i].size() == temp.size()) {
//					if (jinwei2 > 0) {
//						temp.resize(second[i].size() + 1);
//						temp[j + 1] = (char)(jinwei2 + '0');
//						continue;
//					}
//				}
//
//				if (j == temp.size() && (second[i].size() - temp.size()) > 0) {
//					
//					int cuowei = second[i].size() - temp.size();
//					temp.resize(second[i].size());
//					int k = 0;
//					int geiweitmp = 0;
//					int jinweitmp = 0;
//					for (k = 0; k < cuowei; k++) {
//						int a = (second[i][j+k] - '0' + jinwei2);
//						geiweitmp = a % 10;
//						jinweitmp = a / 10;
//
//						temp[j + k] = (char)(geiweitmp + '0');
//
//						//temp[j + k] = (char)(second[i][j + k] - '0' + jinwei2 + '0');
//						//temp.resize(second[i].size() + 1);
//						//temp[j + 1 + k] = (char)(jinweitmp + '0');
//
//					}
//					if (k == 2 && jinweitmp > 0) {
//						temp.resize(second[i].size() + 1);
//						temp[j + k] = (char)(jinweitmp + '0');
//					}
//					
//					continue;
//				}
//				deshu = (temp[j] - '0') + (second[i][j] - '0') + jinwei2;
//				gewei2 = deshu % 10;
//				jinwei2 = deshu / 10;
//				temp[j] = (char)(gewei2 + '0');
//			}
//		}
//		
//		for (int i = 0; i < temp.size(); i++) {
//			ret.push_back(temp[i]);
//		}
//		reverse(ret.begin(), ret.end());
//		return ret;
//	}
//};

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		int len1 = num1.size();
		int len2 = num2.size();
		vector<int> ret(len1 + len2);
		string s;

		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());

		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j) {
				ret[i + j] += (num1[i] - '0') * (num2[j] - '0');
			}
		}

		for (int i = 0; i < len1+len2; ++i) {
			if (ret[i] > 9) {
				int tmp = ret[i];
				ret[i] = tmp % 10;
				ret[i + 1] += tmp / 10;
			}
		}

		int pos = ret[len1 + len2 - 1] == 0 ? len1 + len2 - 2 : len1 + len2 - 1;
		for (; pos >= 0; --pos) {
			s += (ret[pos] + '0');
		}
		return s;
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->multiply("123", "456");
	return 0;
}