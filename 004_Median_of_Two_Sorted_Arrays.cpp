//
// Created by Jie Huang on 9/28/16.
//

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int total = n + m;
        if(total & 0x1)
            return find_k(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
        else
            return (find_k(nums1.begin(), m, nums2.begin(), n, total / 2) \
                    + find_k(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;

    }

    double find_k(vector<int>::iterator iter1, int m, vector<int>::iterator iter2, int n, int k)
    {
        if(m > n) return find_k(iter2, n, iter1, m, k);

        if(m == 0) return *(iter2 + k - 1);
        if(k == 1) return min(*iter1, *iter2);

        int ia = min(m, k / 2);
        int ib = k - ia;
        if(*(iter1 + ia - 1)> *(iter2 + ib -1))
            return find_k(iter1, m, iter2 + ib, n - ib, k - ib);
        else if(*(iter1 + ia - 1) < *(iter2 + ib -1))
            return find_k(iter1 + ia, m - ia, iter2, n, k - ia);
        else
            return iter1[ia - 1];
    }

};