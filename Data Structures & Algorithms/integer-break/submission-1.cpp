class Solution {
public:
    int solve(int index, vector<int>& dp) {
        if(index <= 1) return 1;
        if(dp[index] != -1) return dp[index];

        int ans = INT_MIN;

        for(int i = 1 ; i < index ; i++) {
            int notBreak = index - i;
            int breakIt = solve(index - i, dp);

            ans = max(ans, i * max(notBreak, breakIt));
        }

        return dp[index] = ans;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};