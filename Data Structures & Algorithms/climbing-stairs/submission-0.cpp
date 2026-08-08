class Solution {
public:
    int solve(int index, vector<int>& dp) {
        if(index == 0) return 1;

        if(dp[index] != -1) return dp[index];

        int fs = solve(index-1, dp);
        int ss = 0;
        if(index > 1) {
            ss = solve(index-2, dp);
        }

        return dp[index] = fs+ss;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
