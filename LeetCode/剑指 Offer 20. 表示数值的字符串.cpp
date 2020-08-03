#include "iostream"
#include "vector"
#include <algorithm>
#include <string>
#include <map>
using namespace std;

//class Solution {
//public:
//	bool isNumber(string s) {
//		vector<map<char, int>> states;
//		map<char, int> temp;
//		// s����sign��������
//		// d����digit������
//
//		// ���б�֮���״̬ת�Ƽ�Ϊ�Ƿ�����
//
//		// 0��ͷ���ո�״̬
//		temp[' '] = 0;  // ���� �ո� ���� �ո�״̬0
//		temp['s'] = 1;  // ���� ������ ���� ����״̬1
//		temp['d'] = 2;  // ���� ���� ���� С����ǰ����״̬2
//		temp['.'] = 4;	// ���� С���� ���� ǰΪ��С�������λ����״̬4
//		states.push_back(temp);
//		temp.clear();
//		// 1������״̬
//		temp['d'] = 2;  // ���� ���� ���� С����ǰ������״̬2
//		temp['.'] = 4;  // ����С���� ���� ǰΪ��С�������λ����״̬4
//		states.push_back(temp);
//		temp.clear();
//		// 2��С����ǰ����״̬
//		temp['d'] = 2;  // ���� ���� ���� С����ǰ������״̬2
//		temp['.'] = 3;  // ���� С���� ���� ǰ�ǿ�С����������״̬3
//		temp['e'] = 5;	// ���� e ���� ָ������״̬5
//		temp[' '] = 8;	// ���� �ո� ���� β���ո�״̬8
//		states.push_back(temp);
//		temp.clear();
//		// 3��ǰ�ǿ�С����������״̬
//		temp['d'] = 3;	// ���� ���� ���� ǰ�ǿ�С����������״̬3
//		temp['e'] = 5;	// ���� e ���� ָ������״̬5
//		temp[' '] = 8; 	// ���� �ո� ����β���ո�״̬8
//		states.push_back(temp);
//		temp.clear();
//		// 4��ǰΪ��С�������λ����״̬4
//		temp['d'] = 3; 	// ���� ���� ���� ǰ�ǿ�С����������״̬3
//		states.push_back(temp);
//		temp.clear();
//		// 5��ָ������״̬5
//		temp['s'] = 6;  // ���� ������ ���� ָ����ķ���״̬6
//		temp['d'] = 7;	// ���� ���� ���� ָ��λ������״̬7
//		states.push_back(temp);
//		temp.clear();
//		// 6��ָ����ķ���״̬
//		temp['d'] = 7;  // ���� ���� ���� ָ��λ������״̬7
//		states.push_back(temp);
//		temp.clear();
//		// 7��ָ��λ������״̬
//		temp['d'] = 7;  // ���� ���� ���� ָ��λ������״̬7
//		temp[' '] = 8;  // ���� �ո� ���� β���ո�״̬8
//		states.push_back(temp);
//		temp.clear();
//		// 8��β���ո�״̬
//		temp[' '] = 8;  // ���� �ո� ���� β���ո�״̬8
//		states.push_back(temp);
//		temp.clear();
//
//		// ��ʼ״̬����0״̬
//		int p = 0;
//		// ״̬ת�Ƶ�����key
//		char t;
//		// ���ַ�
//		for (int i = 0; i < s.length(); i++) {
//			char c = s[i];
//			// ��������֣�key='d'
//			if (c >= '0'&&c <= '9') {
//				t = 'd';
//			}
//			// ����������ţ�key='s'
//			else if (c == '+' || c == '-') {
//				t = 's';
//			}
//			// ����������ַ���key='c'��������'.' ' ' �����Ƿ��ַ�
//			else {
//				t = c;
//			}
//			map<char, int>::iterator it = states[p].find(t);
//			// ����Ҳ������״̬ת�ƣ���Ƿ�����
//			if (it == states[p].end()) {
//				return false;
//			}
//			// ����ҵ�����ȡת�ƺ��״̬
//			p = (int)it->second;
//		}
//		// �Ƿ��������β��״̬2 3 7 8
//		return p == 2 || p == 3 || p == 7 || p == 8;
//	}
//};

class Solution {
public:
	using sIter = string::iterator;//typedef
	sIter sEnd;

	bool scanNumber(sIter& iter) {//�����֣��Ҳ�������false
		bool have_number = false;
		while (iter != sEnd && (*iter) >= '0' && (*iter) <= '9') {
			have_number = true;
			iter++;
		}
		return have_number;
	}

	bool scanInteger(sIter& iter) {//�����֣��Ҳ�������false(��λ��Ϊ+��-)
		if (*iter == '+' || *iter == '-') iter++;
		return scanNumber(iter);
	}

	bool isNumber(string s) {
		if (s.empty()) return false;
		sIter iter = s.begin();
		sEnd = s.end();
		while (*iter == ' ') iter++;//ȥ�ո�
		bool result = scanInteger(iter);//��A����λ
		if (*iter == '.') {//����С���㣬����BС��λ
			iter++;
			result |= scanNumber(iter);//С��λ������λ����һ������
		}
		if (*iter == 'e') {//����e������ָ��λ
			iter++;
			result = result && scanInteger(iter);//����e��ָ��λC�������

		}
		if(iter!=sEnd)
			while (*iter == ' ') iter++;//ȥ�ո�
		return result && iter == s.end();//�������β������֮ǰ���򣬷���true
	}
};

int main() {
	Solution *solution = new Solution();
	cout << solution->isNumber("1.2.3");
	return 0;
}