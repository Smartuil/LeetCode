#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	//int minArray(vector<int>& numbers) {
	//	//if (numbers.size() == 0)return 0;
	//	//sort(numbers.begin(), numbers.end());
	//	//return numbers[0];
	//	int low = 0;
	//	int high = numbers.size() - 1;
	//	while (low < high) {
	//		int pivot = low + (high - low) / 2;
	//		if (numbers[pivot] < numbers[high]) {
	//			high = pivot;
	//		}
	//		else if (numbers[pivot] > numbers[high]) {
	//			low = pivot + 1;
	//		}
	//		else {
	//			high -= 1;
	//		}
	//	}
	//	return numbers[low];
	//}

	int minArray(vector<int>& numbers) {
		int i = 0;
		int j = numbers.size() - 1;
		while (i < j) {
			int mid = i + (j - i) / 2;
			if (numbers[mid] < numbers[j]) {
				j = mid;
			}
			else if (numbers[mid] > numbers[j]) {
				i = mid + 1;
			}
			else
			{
				j--;
			}
		}
		return numbers[i];
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> numbers = { 3,4,5,1,2 };
	cout << solution->minArray(numbers);
	return 0;
}