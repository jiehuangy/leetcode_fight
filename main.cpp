#include <iostream>
#include "001_two_sum.cpp"
#include <vector>

using namespace std;

int main() {
    vector<int> nums={1,3,1,1};

    Solution sol;
    bool result = sol.search(nums, 3);
    cout << result << endl;
    return 0;
}