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
        // vector<int> dp(n+1, -1);
        // return solve(n, dp);
        vector<int> dp(n+1, 0);
        dp[0] = 1; //base case
        int curr = 0, prev = 1, prev2 = 0;
        for(int i = 1 ; i <= n ; i++) {
            // int fs = dp[i-1];
            int fs = prev;
            int ss = 0;
            if(i > 1) {
                // ss = dp[i-2];
                ss = prev2;
            }
            int temp = curr;
            curr = prev+prev2;
            prev2 = prev;
            prev = curr;
        }

        return curr;
    }
};
