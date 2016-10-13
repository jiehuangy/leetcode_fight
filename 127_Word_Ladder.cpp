#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
    {
        if(beginWord == "" || endWord == "" || wordList.empty()) return 0;

        queue<string> que;
        que.push(beginWord);
        que.push("FLAG");
        int ladlen = 1;

        while(!que.empty())
        {
            string cur = que.front();
            que.pop();
            if(cur == endWord) return ladlen;
            if(checkTransformation(cur, endWord)) return ladlen + 1;

            if(cur == "FLAG" && !que.empty())
            {
                ladlen++;
                que.push("FLAG");
                continue;
            }

            for(auto it = wordList.begin(); it != wordList.end();)
            {
                if(checkTransformation(cur, *it))
                {
                    que.push(*it);
                    it = wordList.erase(it);
                }
                else
                    it++;
            }
        }
        return 0;
    }

    bool checkTransformation(string a, string b)
    {
        int diff = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) diff++;
            if(diff > 1) break;
        }
        return diff < 2;
    }
};