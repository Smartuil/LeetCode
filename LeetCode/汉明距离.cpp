#include "iostream"

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int xyor = x ^ y;
        int distance = 0;
        while (xyor != 0) {
            if (xyor %2 == 1)
                distance += 1;
            xyor = xyor >> 1;
        }
        return distance;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << solution->hammingDistance(1, 4);
    return 0;
}