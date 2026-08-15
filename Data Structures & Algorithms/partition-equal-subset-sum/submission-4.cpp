class Solution {
public:
    bool solve(int index, int sum, vector<int>& nums, vector<vector<int>>& dp, int offset) {
        if(index == 0) {
            if(sum + nums[0] == 0 || sum - nums[0] == 0) {
                return true;
            }
            return false;
        }

        if(dp[index][sum + offset] != -1) return dp[index][sum + offset];

        int add = solve(index-1, sum+nums[index], nums, dp, offset);
        int subtract = solve(index-1, sum-nums[index], nums, dp, offset);

        return dp[index][sum + offset] = add||subtract;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) {
            sum+= num;
        }
        int offset = sum; 
        vector<vector<int>> dp (n, vector<int>(2*sum+1, -1));
        return solve(n-1, 0, nums, dp, offset);
    }
};
