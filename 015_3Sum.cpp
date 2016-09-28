//
// Created by Jie Huang on 9/28/16.
//

#include <vector>
using  namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        if(nums.size() < 3) return result;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else if(nums[i] + nums[left] + nums[right] < 0)
                    left++;
                else
                {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++; right--;
                    while(nums[left] == nums[left - 1]) left++;
                }
            }
        }
        return result;
    }
};
