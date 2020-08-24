#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string algorithm(char a[], char b[], char c[]) {
	string ret;
	int fenzi = 0;
	int fenmu = 0;
	int sign = 1;
	if (b[0] == '+') {
		if ((a[2] - '0') % (c[2] - '0') == 0) {
			if ((a[2] - '0') == (c[2] - '0')) {
				fenzi = (a[0] - '0') + (c[0] - '0');
				fenmu = a[2] - '0';
				while (fenzi % 2 == 0 && fenmu % 2 == 0) {
					fenzi /= 2;
					fenmu /= 2;
				}
				ret = to_string(fenzi) + "/" + to_string(fenmu);
			}//分母不等
			else
			{
				int maxNum = max((a[2] - '0'), (c[2] - '0'));
				if (maxNum == (a[2] - '0')) {
					int tmp = (a[2] - '0') / (c[2] - '0');
					int tmpFenzi = (c[0] - '0') * tmp;
					int tmpFenmu = (c[2] - '0') * tmp;
					fenzi = (a[0] - '0') + tmpFenzi;
					fenmu = a[2] - '0';
					while (fenzi % 2 == 0 && fenmu % 2 == 0) {
						fenzi /= 2;
						fenmu /= 2;
					}
					ret = to_string(fenzi) + "/" + to_string(fenmu);
				}
				else
				{
					int tmp = (c[2] - '0') / (a[2] - '0');
					int tmpFenzi = (a[0] - '0') * tmp;
					int tmpFenmu = (a[2] - '0') * tmp;
					fenzi = tmpFenzi + (c[0] - '0');
					fenmu = c[2] - '0';
					while (fenzi % 2 == 0 && fenmu % 2 == 0) {
						fenzi /= 2;
						fenmu /= 2;
					}
					ret = to_string(fenzi) + "/" + to_string(fenmu);
				}
			}
		}//分子分母需要相乘
		else
		{
			int tmpFenzi1 = (a[0] - '0') * (c[2] - '0');
			int tmpFenmu1 = (a[2] - '0') * (c[2] - '0');
			int tmpFenzi2 = (c[0] - '0') * (a[2] - '0');
			int tmpFenmu2 = (c[2] - '0') * (a[2] - '0');

			fenzi = tmpFenzi1 + tmpFenzi2;
			fenmu = tmpFenmu1;
			while (fenzi % 2 == 0 && fenmu % 2 == 0) {
				fenzi /= 2;
				fenmu /= 2;
			}
			ret = to_string(fenzi) + "/" + to_string(fenmu);
		}
	}
	else if (b[0] == '-') {
		if ((a[2] - '0') % (c[2] - '0') == 0) {
			if ((a[2] - '0') == (c[2] - '0')) {
				fenzi = (a[0] - '0') - (c[0] - '0');
				fenmu = a[2] - '0';
				while (fenzi % 2 == 0 && fenmu % 2 == 0) {
					fenzi /= 2;
					fenmu /= 2;
				}
				ret = to_string(fenzi) + "/" + to_string(fenmu);
			}//分母不等
			else
			{
				int maxNum = max((a[2] - '0'), (c[2] - '0'));
				if (maxNum == (a[2] - '0')) {
					int tmp = (a[2] - '0') / (c[2] - '0');
					int tmpFenzi = (c[0] - '0') * tmp;
					int tmpFenmu = (c[2] - '0') * tmp;
					fenzi = (a[0] - '0') - tmpFenzi;
					fenmu = a[2] - '0';
					while (fenzi % 2 == 0 && fenmu % 2 == 0) {
						fenzi /= 2;
						fenmu /= 2;
					}
					ret = to_string(fenzi) + "/" + to_string(fenmu);
				}
				else
				{
					int tmp = (c[2] - '0') / (a[2] - '0');
					int tmpFenzi = (a[0] - '0') * tmp;
					int tmpFenmu = (a[2] - '0') * tmp;
					fenzi = tmpFenzi - (c[0] - '0');

					fenmu = c[2] - '0';
					while (fenzi % 2 == 0 && fenmu % 2 == 0) {
						fenzi /= 2;
						fenmu /= 2;
					}
					ret = to_string(fenzi) + "/" + to_string(fenmu);
				}
			}
		}//分子分母需要相乘
		else
		{
			int tmpFenzi1 = (a[0] - '0') * (c[2] - '0');
			int tmpFenmu1 = (a[2] - '0') * (c[2] - '0');
			int tmpFenzi2 = (c[0] - '0') * (a[2] - '0');
			int tmpFenmu2 = (c[2] - '0') * (a[2] - '0');

			fenzi = tmpFenzi1 - tmpFenzi2;
			fenmu = tmpFenmu1;
			while (fenzi % 2 == 0 && fenmu % 2 == 0) {
				fenzi /= 2;
				fenmu /= 2;
			}
			ret = to_string(fenzi) + "/" + to_string(fenmu);
		}
	}
	else if (b[0] == '*') {	
		fenzi = (a[0] - '0') * (c[0] - '0');
		fenmu = (a[2] - '0') * (c[2] - '0');
		while (fenzi % 2 == 0 && fenmu % 2 == 0) {
			fenzi /= 2;
			fenmu /= 2;
		}
		ret = to_string(fenzi) + "/" + to_string(fenmu);
	}
	else
	{
		fenzi = (a[0] - '0') * (c[2] - '0');
		fenmu = (a[2] - '0') * (c[0] - '0');
		while (fenzi % 2 == 0 && fenmu % 2 == 0) {
			fenzi /= 2;
			fenmu /= 2;
		}
		ret = to_string(fenzi) + "/" + to_string(fenmu);
	}


	return ret;
}

int main1() {
	char a[3];
	char b[1];
	char c[3];
	while (cin >> a >> b >> c) {
		string ret = algorithm(a, b, c);
		for (auto s : ret) {
			cout << s;
		}
	}
	return 0;
}