class Solution {
public:
    int n , m;
    void dfs(int i, int j, vector<vector<char>>& a){
        if(i<0 || j<0 || i>=n || j>=m || a[i][j] == '0'){
            return;
        }
        a[i][j] = '0';
        dfs(i + 1, j ,a);
        dfs(i -1, j ,a);
        dfs(i, j+1,a);
        dfs(i,j-1,a);
    }
    int numIslands(vector<vector<char>>& grid) {
        n= grid.size();
        m=grid[0].size();
        int c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    c++;
                    dfs(i,j,grid);
                }
            }
        }
        return c;
    }
};