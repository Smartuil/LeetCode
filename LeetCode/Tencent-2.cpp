#include "iostream"
#include "string"
#include "map"
using namespace std;


int main() {
	string s;
	int count = 0;
	int k;
	map<int, string> vecS;
	while (cin >> s >> k) {
		int len = s.size();
		int i = 0;
		
		while (i < len) {
			int sunLen = 1;
			while (sunLen <= len) {
				if (i > 0 && s[i] == s[i - 1]) {
					sunLen++;
					continue;
				}
				vecS.insert({ count++, s.substr(i, sunLen++) });
				if (vecS.size() == k) {
					cout << vecS[k-1];
					break;
				}
				if (vecS.size() == k) {
					break;
				}
			}		
			++i;
		}
	}
	return 0;
}