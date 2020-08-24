#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

int solution(int l, int r, int m, vector<int> &vec) {
	if (l > r) {
		return 0;
	}
	int cur = -1;
	int minNum = 1 << 30;
	int sum = 0;
	for (int i = l; i <= r; ++i) {
		if (minNum > vec[i]) {
			minNum = vec[i];
			cur = i;
		}
		if (vec[i] > m) {
			sum++;
		}
	}

	int tmp = vec[cur] - m;
	if (tmp < 0) {
		tmp = 0;
	}
	return min(
		sum, 
		solution(l, cur - 1, max(vec[cur], m), vec) + solution(cur + 1, r, max(vec[cur], m), vec) + tmp);
}

int main() {
	int n;
	vector<int> vec(5005);
	//while (cin >> n) {
	//	for (int i = 1; i <= n; ++i) {
	//		int tmp;
	//		cin >> tmp;
	//		vec[i] = tmp;
	//	}
	//	int ret = solution(1, n, 0, vec);
	//	cout << ret << endl;
	//}
	vec = { 0,2,1,2,2,1 };
	int ret = solution(1, 5, 0, vec);
	cout << ret << endl;
	return 0;
}