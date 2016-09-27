//
// Created by Jie Huang on 9/27/16.
//
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size();
        while(l < r)
        {
            int m = l + (r - l) / 2;
            if(nums[m] == target) return true;

            if(nums[l] < nums[m])
            {
                if(nums[l] <= target && target < nums[m])
                    r = m;
                else
                    l = m + 1;
            }
            else if(nums[m] < nums[r])
            {
                if(nums[m] <= target && target <= nums[r])
                    l = m + 1;
                else
                    r = m;
            }
            else
            {
                l++;
            }
        }
        return false;
    }
};
