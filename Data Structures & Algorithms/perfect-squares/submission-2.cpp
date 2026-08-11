class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if(n<=0) {
            return 0;
        }

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;

        for(int i = sqrt(n) ; i>= 1 ; i--) {
            ans = min(ans, 1 + solve(n-(i*i), dp));
        }

        return dp[n] = ans;
    }
    int numSquares(int n) {
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);

        vector<int> dp(n+1, 0);

        dp[0] = 0;
        for(int i = 1 ; i <= n ; i++){
            int ans = INT_MAX;

            for(int j = sqrt(i); j>= 1 ; j--) {
                ans = min(ans, 1 + dp[i-(j*j)]);
            }
            dp[i] = ans;
        }

        return dp[n];
    }
};