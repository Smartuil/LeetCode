#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
using namespace std;

//class Solution {
//public:
//	vector<int> printNumbers(int n) {
//		int i = 1;
//		vector<int> ret;
//		int c = i / pow(10, n);
//		while (c == 0) {
//			ret.push_back(i);
//			c = i / pow(10, n);
//			i++;
//		}
//		ret.erase(ret.end() - 1);
//		int c = pow(10, n);
//		while (i < c) {
//			ret.push_back(i);
//			i++;
//		}
//		return ret;
//	}
//};

//https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/c-3chong-jie-fa-by-xdb/
//大数解法string版
//class Solution {
//public:
//	vector<int> res;
//	vector<int> printNumbers(int n) {
//		if (n <= 0) return res;
//		//创建一个能容纳最大值的字符数组
//		string number(n, '0');
//		//初始全部设置为0
//		while (!Increment(number))
//		{
//			saveNumber(number);
//		}
//		return res;
//	}
//	bool Increment(string& number) {
//		//注意要使用引用传递，否则无法修改number
//		bool isOverflow = false;//检测是否越界
//		int nTakeOver = 0;//存储进位
//		int nLength = number.size();
//		for (int i = nLength - 1; i >= 0; i--)
//		{
//			int nSum = number[i] - '0' + nTakeOver;
//			if (i == nLength - 1)
//				//如果是第一位，进位
//			{
//				nSum++;
//			}
//			if (nSum >= 10)//有进位
//			{
//				if (i == 0)
//					//如果是最高位有进位，说明超过了给定得到最大值，越界
//				{
//					isOverflow = true;
//				}
//				else
//				{
//					nTakeOver = 1;
//					number[i] = nSum - 10 + '0';//对第i位进行设置
//				}
//			}
//			else//没有进位
//				//设置第i位数字
//				//并直接跳出循环
//			{
//				number[i] = nSum + '0';
//				break;
//			}
//		}
//		return isOverflow;
//	}
//	void saveNumber(string number)
//		//由于此处输出，不需要修改number，因此不需要加引用
//	{
//		string s = "";
//		bool isBegin0 = true;
//		string::iterator it = number.begin();
//		while (it != number.end())
//		{
//			if (isBegin0 && *it != '0') isBegin0 = false;
//			if (!isBegin0)
//			{
//				s += *it;
//			}
//			it++;
//		}
//		int num = stoi(s);
//		res.push_back(num);
//	}
//};

//class Solution {
//public:
//	vector<int> printNumbers(int n) {
//		vector<int> ret;
//		int c = pow(10, n);
//		int i = 1;
//		while (i < c) {
//			ret.push_back(i);
//			i++;
//		}
//		return ret;
//	}
//};


class Solution {
public:
	void printNumbers(int n, int index, string& str, vector<int> &rs) {
		if (index == n) {
			int num = atoi(str.c_str());
			if(num)
				rs.push_back(num);
			return;
		}
		else
		{
			for (int i = 0; i < 10; i++) {
				str[index] = i + '0';
				printNumbers(n, index + 1, str, rs);
			}
		}
	}

	vector<int> printNumbers(int n) {
		vector<int> rs;
		string str;
		str.resize(n);
		printNumbers(n, 0, str, rs);
		return rs;
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> ret = solution->printNumbers(2);
	for (auto i : ret) {
		cout << i << endl;
	}
	return 0;
}