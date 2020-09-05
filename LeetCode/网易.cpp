//#include "iostream"
//#include "vector"
//#include <unordered_map>
//#include <deque>
//#include <string>
//using namespace std;
//
//
////5 2
////1 2 3 4 5
////5
////left take 1
////right take 2
////left return 3
////right keep
////right take 4
////10
////left take 1
////left keep
////left take 2
////left keep
////left take 3
////left keep
////left take 4
////left keep
////left take 5
////left keep
//
//int main() {
//	int n, m;
//	vector<deque<int>> cao;
//	unordered_map<int, int> bianhao2price;
//	int caozuocishu;
//	int jiage;
//	int huafei=0;
//	string first;
//	string second;
//	int xuhao;
//	unordered_map<string, int> naquwupin;
//
//	while (cin >> n >> m) {
//		cao.resize(n+1);
//
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 0; j <= 100; ++j) {
//				cao[i].push_front(i);
//			}
//			cin >> jiage;
//			bianhao2price[i] = jiage;
//		}
//		while (m > 0) {
//			huafei = 0;
//			cin >> caozuocishu;
//			while (caozuocishu > 0) {
//				cin >> first;
//				cin >> second;
//				if (second != "keep") {
//					cin >> xuhao;
//				}
//				
//				if (first == "left") {
//					if (second == "take") {
//						//huafei += bianhao2price[xuhao];
//						naquwupin[first] = cao[xuhao].front();
//						cao[xuhao].pop_front();
//					}
//					else if (second == "return") {
//						//huafei -= bianhao2price[naquwupin[first]];
//						cao[xuhao].push_front(naquwupin[first]);
//						naquwupin.erase(first);
//					}
//					else
//					{
//						huafei += bianhao2price[naquwupin[first]];
//						naquwupin.erase(first);
//					}
//				}
//				else {
//					if (second == "take") {
//						//huafei += bianhao2price[xuhao];
//						naquwupin[first] = cao[xuhao].front();
//						cao[xuhao].pop_front();
//					}
//					else if (second == "return") {
//						//huafei -= bianhao2price[naquwupin[first]];
//						cao[xuhao].push_front(naquwupin[first]);
//						naquwupin.erase(first);
//					}
//					else
//					{
//						huafei += bianhao2price[naquwupin[first]];
//						naquwupin.erase(first);
//					}
//				}
//				caozuocishu--;
//				//cout << huafei << "aasa"<<endl;
//			}
//			if (!naquwupin.empty()) {
//				for (auto i : naquwupin) {
//					huafei += bianhao2price[i.second];
//				}
//			}
//			cout << huafei << endl;
//			m--;
//		}
//	}
//	return 0;
//}


#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

void sort(vector<int> &vec) {
	for (int i = 0; i < vec.size() - 2; ++i) {
		if (vec[i] * vec[i + 1] > vec[i + 1] * vec[i + 2]) {
			swap(vec[i], vec[i + 2]);
		}
	}
}

int main() {
	int n;
	vector<int> vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec);
	for (int i = 0; i < n; i++) {
		cout << vec[i] << " ";
	}
	return 0;
}