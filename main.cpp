#include <iostream>
#include "004_Median_of_Two_Sorted_Arrays.cpp"
#include <vector>

using namespace std;

int main() {
    vector<int> nums1={1,2};
    vector<int> nums2={1,2};

    Solution sol;
    double a = sol.find_k(nums1.begin(), 2, nums2.begin(),2,2);
    double b = sol.find_k(nums1.begin(), 2, nums2.begin(),2,3);
    cout << a << endl;
    cout << b << endl;
    return 0;
}