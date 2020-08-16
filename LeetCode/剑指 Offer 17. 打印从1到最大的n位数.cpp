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
//�����ⷨstring��
//class Solution {
//public:
//	vector<int> res;
//	vector<int> printNumbers(int n) {
//		if (n <= 0) return res;
//		//����һ�����������ֵ���ַ�����
//		string number(n, '0');
//		//��ʼȫ������Ϊ0
//		while (!Increment(number))
//		{
//			saveNumber(number);
//		}
//		return res;
//	}
//	bool Increment(string& number) {
//		//ע��Ҫʹ�����ô��ݣ������޷��޸�number
//		bool isOverflow = false;//����Ƿ�Խ��
//		int nTakeOver = 0;//�洢��λ
//		int nLength = number.size();
//		for (int i = nLength - 1; i >= 0; i--)
//		{
//			int nSum = number[i] - '0' + nTakeOver;
//			if (i == nLength - 1)
//				//����ǵ�һλ����λ
//			{
//				nSum++;
//			}
//			if (nSum >= 10)//�н�λ
//			{
//				if (i == 0)
//					//��������λ�н�λ��˵�������˸����õ����ֵ��Խ��
//				{
//					isOverflow = true;
//				}
//				else
//				{
//					nTakeOver = 1;
//					number[i] = nSum - 10 + '0';//�Ե�iλ��������
//				}
//			}
//			else//û�н�λ
//				//���õ�iλ����
//				//��ֱ������ѭ��
//			{
//				number[i] = nSum + '0';
//				break;
//			}
//		}
//		return isOverflow;
//	}
//	void saveNumber(string number)
//		//���ڴ˴����������Ҫ�޸�number����˲���Ҫ������
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