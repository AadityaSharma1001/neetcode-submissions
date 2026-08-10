class Solution {
public:
    long long solve(int index, vector<int>& stoneValue, vector<long long>& dp) {
        int n = stoneValue.size();
        if (index >= n) return 0;
        long long sum = 0;
        long long ans = LLONG_MIN;

        if(dp[index] != -1) return dp[index];

        for (int i = index; i < min(n, index + 3); i++) {
            sum += stoneValue[i];

            ans = max(ans, sum - solve(i + 1, stoneValue, dp));
        }

        return dp[index] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<long long> dp(n+1, -1);

        long long ans = solve(0, stoneValue, dp);

        if (ans > 0) {
            return "Alice";
        } else if (ans == 0) {
            return "Tie";
        } else {
            return "Bob";
        }
    }
};