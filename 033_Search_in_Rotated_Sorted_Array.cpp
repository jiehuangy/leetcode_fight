//
// Created by Jie Huang on 9/28/16.
//
#include <vector>
using  namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return mid;

            if(nums[l] <= nums[mid])
            {
                if(target < nums[mid] && nums[l] <= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if(target <= nums[r] && nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
