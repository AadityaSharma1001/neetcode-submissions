class Solution {
public:
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(amount == 0) {
            return 1;
        }
        if(index < 0 || amount < 0) {
            return 0;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int takeSame = solve(index, amount-coins[index], coins, dp);
        int skip = solve(index-1, amount, coins, dp);

        return dp[index][amount] = skip + takeSame;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        return solve(n-1, amount, coins, dp);
    }
};
