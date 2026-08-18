class Solution {
   public:
    int solve(int index, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (index < 0) {
            return 0;
        }

        int offset = 1000;

        if (dp[index][prev + offset] != -1) {
            return dp[index][prev + offset];
        }

        int take = 0;

        if (nums[index] < prev) {
            take = 1 + solve(index - 1, nums[index], nums, dp);
        }

        int notTake = solve(index - 1, prev, nums, dp);

        return dp[index][prev + offset] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(2002, -1));

        return solve(n - 1, 1001, nums, dp);
    }
};