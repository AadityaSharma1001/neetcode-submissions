class Solution {
public:
    int solve(int i, int j, string text1, string text2, vector<vector<int>>& dp) {
        if (i == text1.length() || j == text2.length()) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }

        int skipText1 = solve(i + 1, j, text1, text2, dp);
        int skipText2 = solve(i, j + 1, text1, text2, dp);

        return dp[i][j] = max(skipText1, skipText2);
    }

    //base case
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(i, j, text1, text2, dp);
    }
};
