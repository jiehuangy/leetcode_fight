#include <iostream>
#include "016_3Sum_Closest.cpp"
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {0,1,2 ,-3};
    int target = 3;
    Solution sol;
    sol.threeSumClosest(nums, 0);
    return 0;
}