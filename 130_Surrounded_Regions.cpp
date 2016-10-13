//
// Created by Jie Huang on 07/10/2016.
//

#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;

        for(int i = 0; i < m; i++)
        {
            bfs(i, 0, board);
            bfs(i, n - 1, board);
        }
        for(int j = 0; j < n; j++)
        {
            bfs(0, j, board);
            bfs(m - 1, j, board);
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'V')
                    board[i][j] = 'O';
            }
    }

    void bfs(int x, int y, vector<vector<char>>& board)
    {
        if(board[x][y] != 'O') return;
        int m = board.size();
        int n = board[0].size();
        board[x][y] = 'V';
        queue<pair<int,int>> que;
        que.push(make_pair(x,y));
        while(!que.empty())
        {
            auto p = que.front();
            que.pop();

            for(int i = 0; i < 4; i++)
            {
                int nextx = p.first + dirc[i][0];
                int nexty = p.second + dirc[i][1];
                if(0 <= nextx && nextx < m && 0 <= nexty && nexty < n && board[nextx][nexty] == 'O') {
                    que.push(make_pair(nextx, nexty));
                    board[nextx][nexty] = 'V';
                }
            }
        }
    }
    vector<vector<int>> dirc = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
};