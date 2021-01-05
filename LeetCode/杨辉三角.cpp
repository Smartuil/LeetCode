#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};

int main() {
    Solution* solution = new Solution();
    vector<vector<int>> ret = solution->generate(5);
    for (auto tmp : ret) {
        for (auto tmp2 : tmp) {
            cout << tmp2;
        }
        cout << endl;
    }
    return 0;
}