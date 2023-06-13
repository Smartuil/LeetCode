#include "iostream"
#include "vector"
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	string freqAlphabets(string s) {
		string ret;

		map<string, int> keyMap;

		for (int i = 'a', j = 1; i <= 'i'; i++, j++) {
			keyMap[to_string(j)] = i;
		}

		for (int i = 'j', j = 10; i <= 'z'; i++, j++) {
			keyMap[to_string(j).append("#")] = i;
		}

		while(s.size() > 0){
			int posSharp = s.find("#", 2);

			if (posSharp == 2) {
				string tmp = s.substr(0, 3);
				ret.push_back(((char)keyMap[tmp]));
				s = s.substr(3, s.size());
			}
			else {
				string tmp = s.substr(0, 1);
				ret.push_back(((char)keyMap[tmp]));
				s = s.substr(1, s.size());
			}
		}

		return ret;
	}
};

int main() {
	Solution* solution = new Solution();
	string s = "10#";
	cout << solution->freqAlphabets(s);
	return 0;
}