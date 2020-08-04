#include "iostream"
#include "vector"

using namespace std;

void QuickSort(vector<int> &arr, int l, int r) {
	if (l >= r) {
		return;
	}
	int i = l;
	int j = r;
	int key = arr[l];

	while (i < j) {
		while (i < j&&key <= arr[j]) {
			j--;
		}
		if (i < j) {
			arr[i] = arr[j];
			i++;
		}

		while (i < j&&key >= arr[i]) {
			i++;
		}
		if (i < j) {
			arr[j] = arr[i];
			j--;
		}
	}

	arr[i] = key;
	QuickSort(arr, l, i - 1);
	QuickSort(arr, i + 1, r);
}

int main() {
	vector<int> arr = { 2,4,1,66,3,75,4,6,9,23 };
	QuickSort(arr, 0, arr.size() - 1);
	for (auto i : arr) {
		cout << i << " ";
	}
	return 0;
}