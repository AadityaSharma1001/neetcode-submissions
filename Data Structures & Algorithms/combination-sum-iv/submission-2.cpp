class Solution {
public:

    int solve(int target, vector<int>& nums, vector<int>& dp){
        if(target == 0) {
            return 1;
        }

        if(target < 0) {
            return 0;
        }

        if(dp[target] != -1) return dp[target];

        int ans = 0;

        for(int i = 0 ; i < nums.size() ; i++) {
            ans += solve(target-nums[i], nums, dp);
        }

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // vector<int> dp(target+1, -1);
        // return solve(target, nums, dp);

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target ; i++) {
            int ans = 0;
            for(int j = 0 ; j < nums.size() ; j++) {
                if(i-nums[j] >= 0) {
                    ans += dp[i-nums[j]];
                }
            }
            dp[i] = ans;
        }

        return dp[target];
    }
};