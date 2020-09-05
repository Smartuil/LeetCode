#include "iostream"
#include "string"

using namespace std;

string trans(string s, int n) {
	int i = 0;
	string tmp, ret;
	while(i < n) {
		if (s[i] == ' ') {
			ret = ' ' + tmp + ret;
			tmp.clear();
		}
		if (s[i] <= 'Z'&&s[i] >= 'A') tmp += s[i] - 'A' + 'a';
		else if (s[i] >= 'a'&&s[i] <= 'z') tmp += s[i] - 32;
		++i;

	}
	ret = tmp + ret;
	return ret;
}


int main() {
	cout << trans("This is a sample", 16);

	return 0;
}