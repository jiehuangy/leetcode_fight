//
// Created by Jie Huang on 9/28/16.
//

#include <vector>
#include <cmath>
using  namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int result = 0;
        int gap = INT_MAX;
        sort(nums.begin(), nums.end());

        for(auto i = nums.begin(); i != prev(nums.end(), 2); i++)
        {
            if(i > nums.begin() && *i == *(i - 1)) continue;

            auto left = next(i);
            auto right = prev(nums.end());
            while(left < right)
            {
                double sum = *i + *left + *right;
                int new_gap = abs(sum - target);
                if(new_gap < gap)
                {
                    gap = new_gap;
                    result = *i + *left + *right;
                }

                if(sum < target)
                    left++;
                else right--;
            }
        }
        return result;
    }
};
