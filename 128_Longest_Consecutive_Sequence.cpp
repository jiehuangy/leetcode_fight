//
// Created by Jie Huang on 9/28/16.
//

#include <vector>
#include <algorithm>
#include <unordered_set>
using  namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int max_len = 0;
        unordered_set<int> hs;
        for(auto num : nums) hs.insert(num);

        for(auto num : nums)
        {
            if(hs.find(num - 1) == hs.end())
            {
                int m = num + 1;
                while(hs.find(m) != hs.end())
                    m++;
                max_len = max(max_len, m - num );
            }
        }
        return max_len;
    }
};
