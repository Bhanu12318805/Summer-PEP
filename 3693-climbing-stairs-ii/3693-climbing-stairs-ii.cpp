class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] =0;

        for(int i=0; i < n;i++){
            if(dp[i] == INT_MAX){
                continue;
            }
            for(int j = 1;j<=3;j++){
                int m = i+ j;
                if(m >n){
                    break;
                }
                int cost = costs[m - 1] +  j * j;
                dp[m] = min(dp[m], dp[i] + cost);
            }
            
        }
        return dp[n];
    }
};