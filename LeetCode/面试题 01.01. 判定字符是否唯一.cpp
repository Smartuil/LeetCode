#include "iostream"
#include "string"
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isUnique(string astr) {
		//unordered_set<int> s;
		//for (char c : astr) {
		//	if (!s.insert(c).second) {
		//		return false;
		//	}
		//}
		//return true;

		int x = 0;
		for (char c : astr) {
			if (x&(1 << (c - 'a'))) {
				return false;
			}
			else
			{
				x |= (1 << (c - 'a'));
			}
		}
		return true;
	}
};

int main() {

	return 0;
}