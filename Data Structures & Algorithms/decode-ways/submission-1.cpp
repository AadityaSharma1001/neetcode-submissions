class Solution {
   public:
    int solve(int index, string s, vector<int>& dp) {
        if (index == s.length()) {
            return 1;
        }

        if (s[index] == '0') {
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        // One digit at a time
        int one = solve(index + 1, s, dp);

        int two = 0;

        // Take two digits at a time
        if (index + 1 < s.length()) {
            int num = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (num >= 10 && num <= 26) {
                two = solve(index + 2, s, dp);
            }
        }

        return dp[index] = one + two;
    }
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dp);
    }
};
