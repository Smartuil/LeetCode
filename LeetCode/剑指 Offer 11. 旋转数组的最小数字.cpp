#include "iostream"
#include "vector"
#include <algorithm>
using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		//if (numbers.size() == 0)return 0;
		//sort(numbers.begin(), numbers.end());
		//return numbers[0];
		int low = 0;
		int high = numbers.size() - 1;
		while (low < high) {
			int pivot = low + (high - low) / 2;
			if (numbers[pivot] < numbers[high]) {
				high = pivot;
			}
			else if (numbers[pivot] > numbers[high]) {
				low = pivot + 1;
			}
			else {
				high -= 1;
			}
		}
		return numbers[low];
	}
};

int main() {
	Solution *solution = new Solution();
	vector<int> numbers = { 3,4,5,1,2 };
	cout << solution->minArray(numbers);
	return 0;
}