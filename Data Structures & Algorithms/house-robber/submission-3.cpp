class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp) {
        if(index < 0) {
            return 0;
        }
        if(dp[index] != -1) return dp[index];
        int take = nums[index] + solve(index - 2, nums, dp);
        int notTake = solve(index-1, nums, dp);

        return dp[index] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1, -1);
        // return solve(n-1, nums, dp);


        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        int prev2 = 0, prev = nums[0];


        for(int i = 1; i < n ; i++) {
            int take = nums[i];
            if(i > 1) {
                take += prev2;
            }
            int notTake = prev;
            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
