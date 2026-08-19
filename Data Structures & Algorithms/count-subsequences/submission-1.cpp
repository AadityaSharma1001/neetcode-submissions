class Solution {
public:
    int solve(int index1, int index2, string s, string t, vector<vector<int>>& dp) {
        if(index2 == t.length()) {
            return 1;
        }
        if(index1 == s.length()) {
            return 0;
        }
        if(dp[index1][index2] != -1) return dp[index1][index2];

        int take = 0;
        if(s[index1] == t[index2]) {
            take = solve(index1+1, index2+1, s, t, dp);
        }
        int skip = solve(index1+1, index2, s, t, dp);

        return dp[index1][index2] = skip+take;
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, t, dp);
    }
};
