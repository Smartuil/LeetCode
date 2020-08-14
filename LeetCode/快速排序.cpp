#include "iostream"
#include "vector"
#include <time.h>
using namespace std;

//void QuickSort(vector<int> &arr, int l, int r) {
//	//if (l >= r) {
//	//	return;
//	//}
//	//int i = l;
//	//int j = r;
//	//int key = arr[l];
//	//
//	//while (i < j) {
//	//	while (i < j&&key <= arr[j]) {
//	//		j--;
//	//	}
//	//	if (i < j) {
//	//		arr[i] = arr[j];
//	//		i++;
//	//	}
//	//
//	//	while (i < j&&key >= arr[i]) {
//	//		i++;
//	//	}
//	//	if (i < j) {
//	//		arr[j] = arr[i];
//	//		j--;
//	//	}
//	//}
//	//
//	//arr[i] = key;
//	//QuickSort(arr, l, i - 1);
//	//QuickSort(arr, i + 1, r);
//
//	if (l >= r) {
//		return;
//	}
//	int i = l, j = r, key = arr[l];
//	while (i < j) {
//		while (i < j&&arr[j] >= key) {
//			j--;
//		}
//		if (i < j) {
//			arr[i] = arr[j];
//			i++;
//		}
//		while (i < j&&arr[i] <= key) {
//			i++;
//		}
//		if (i < j) {
//			arr[j] = arr[i];
//			j--;
//		}
//	}
//	arr[i] = key;
//	QuickSort(arr, l, i - 1);
//	QuickSort(arr, i + 1, r);
//}

template<typename T>
void quicksort(T data[], int first, int last)
{
	int lower = first + 1;
	int upper = last;
	swap(data[first], data[(first + last) / 2]);
	T bound = data[first];
	while (lower <= upper)
	{
		while (data[lower] < bound)
			lower++;
		while (data[upper] > bound)
			upper--;
		if (lower < upper)
			swap(data[lower++], data[upper--]);
		else lower++;
	}
	swap(data[upper], data[first]);
	if (first < upper - 1)
		quicksort(data, first, upper - 1);
	if (upper + 1 < last)
		quicksort(data, upper + 1, last);
}

//template<class T>
//void quicksort(T data[], int n)
//{
//	int i, max;
//	if (n < 2)
//		return;
//	for (i = 1, max = 0; i < n; i++)
//		if (data[max] < data[i])
//			max = i;
//	swap(data[n - 1], data[max]);
//	quicksort(data, 0, n - 2);  //
//}

void PrintArray(int array[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {
	vector<int> arr = { 2,4,1,66,3,75,4,6,9,23 };
	//QuickSort(arr, 0, arr.size() - 1);
	//for (auto i : arr) {
	//	cout << i << " ";
	//}

	const int NUM = 10;
	int array[NUM] = { 0 };
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < NUM; i++)
	{
		array[i] = rand() % 100 + 1;
	}
	cout << "ÅÅÐòÇ°£º" << endl;
	PrintArray(array, NUM);
	cout << "ÅÅÐòºó£º" << endl;
	quicksort(array, 0, NUM - 1);
	PrintArray(array, NUM);

	return 0;
	return 0;
}