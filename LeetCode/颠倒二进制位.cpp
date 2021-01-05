#include "iostream"

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 31;
        while (n != 0) {
            ret += (n & 1) << power;
            n = n >> 1;
            power -= 1;
        }
        return ret;
    }
};

int main() {
    Solution* solution = new Solution();
    cout << solution->reverseBits(00000010100101);
    return 0;
}