class Solution {
public:
    int solve(int index, int target, vector<int>& nums,
              vector<vector<int>>& dp, int offset) {

        // target is outside possible range
        if (target < -offset || target > offset) {
            return 0;
        }

        if (index == 0) {
            if (target == 0 && nums[0] == 0) {
                return 2;
            }

            if (target - nums[0] == 0 || target + nums[0] == 0) {
                return 1;
            }

            return 0;
        }

        // target + offset converts negative target to valid index
        if (dp[index][target + offset] != -1) {
            return dp[index][target + offset];
        }

        int add = solve(index - 1, target + nums[index],
                        nums, dp, offset);

        int subtract = solve(index - 1, target - nums[index],
                             nums, dp, offset);

        return dp[index][target + offset] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int sum = 0;
        for (int x : nums) {
            sum += x;
        }

        // Impossible target
        if (target > sum || target < -sum) {
            return 0;
        }

        int offset = sum;

        // targets range from -sum to +sum
        vector<vector<int>> dp(
            n, vector<int>(2 * sum + 1, -1)
        );

        return solve(n - 1, target, nums, dp, offset);
    }
};