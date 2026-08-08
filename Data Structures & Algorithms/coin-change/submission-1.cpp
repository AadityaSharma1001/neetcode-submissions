class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<int>& dp) {
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return 1e9;
        }

        if(dp[amount] != -1) return dp[amount];

        int n = coins.size();
        int ans = 1e9;
        for(int i = 0 ; i < n ; i++) {
            ans = min(ans, 1+solve(amount-coins[i], coins, dp));
        }

        return dp[amount] = ans ;
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(1e4+1, -1);
        int ans = solve(amount, coins, dp);

        if(ans >= 1e9) {
            return -1;
        }
       
        return ans;
    }
};
