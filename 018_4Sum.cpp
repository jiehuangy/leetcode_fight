//
// Created by Jie Huang on 9/28/16.
//

#include <vector>
using  namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;

        sort(nums.begin(), nums.end());

        for(auto i = nums.begin(); i != prev(nums.end(), 3); i++)
        {
            if(i > nums.begin() && *i == *(i - 1)) continue;
            for(auto j = next(i); j != prev(nums.end(), 2); j++)
            {
                if(j > next(i) && *j == *(j - 1)) continue;

                auto l = next(j);
                auto r = prev(nums.end());
                while(l < r)
                {
                    int sum = *i + *j + *l + *r;
                    if(sum < target) l++;
                    else if(sum > target) r--;
                    else
                    {
                        result.push_back(vector<int>{*i, *j, *l, *r});
                        l++; r--;
                        while(l < r && *l == *(l - 1)) l++;
                    }
                }
            }
        }
        return result;
    }
};
