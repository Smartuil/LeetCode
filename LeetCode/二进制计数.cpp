#include<iostream>
#include<set>
using namespace std;

int BinaryCount(int n) {
	int count = 0;
	while (n > 0) {
		if (n % 2 == 1)
			++count;
		n = n / 2;
	}
	return count;
}

int main() {
	int T;
	while (cin >> T) {
		while (T > 0) {
			--T;
			int N;
			cin >> N;
			set<int> res;
			while (N > 0) {
				--N;
				int n;
				cin >> n;
				res.insert(BinaryCount(n));
			}
			cout << res.size() << endl;
		}
	}
}