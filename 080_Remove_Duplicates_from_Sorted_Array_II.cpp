//
// Created by Jie Huang on 9/28/16.
//
#include <vector>
using  namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() < 2) return nums.size();

        int cur = 0;
        int count = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[cur] != nums[i])
            {
                count = 1;
                nums[++cur] = nums[i];
            }
            else if(count < 2)
            {
                ++count;
                nums[++cur] = nums[i];
            }
        }
        return cur + 1;
    }
};
