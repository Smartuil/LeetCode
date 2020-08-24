#include "iostream"
#include <queue>
#include "vector"
#include "algorithm"
using namespace std;

long long jisuan(long long a, long long b) {
	long long suma = 0, sumb = 0;
	while (a) {
		suma += a % 10;
		a /= 10;
	}
	while (b) {
		sumb += b % 10;
		b /= 10;
	}
	return sumb + suma;
}

int main() {
	int t;
	long long n;
	
	while (cin >> t) {
		for (long long i = 0; i < t; ++i) {
			//priority_queue<long long> q;
			vector<long long> v;
			v.clear();
			cin >> n;
			long long a, b;
			long long j = 0;
			while (j < n / 2) {
				a = j;
				b = n - j;
				//q.push(jisuan(a, b));
				v.push_back(jisuan(a, b));
				j++;
			}
			sort(v.begin(), v.end());
			cout << v.back();
		}
		
	}
	return 0;
}