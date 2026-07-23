class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        queue<pair<int, pair<int, int>>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 2) {
                    q.push({0,{i, j}});
                }
            }
        }

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        int minTime = 0;

        while(!q.empty()) {
            int time = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            minTime = max(minTime, time);

            for(int i = 0; i < 4; i++) {
                int nr = dr[i] + r;
                int nc = dc[i] + c;

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] == 1) {
                    g[nr][nc] = 2;
                    q.push({time + 1,{nr, nc}});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 1) return -1;
            }
        }

        return minTime;
    }
};