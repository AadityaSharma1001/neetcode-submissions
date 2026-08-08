class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

            if (n <= 1)
                return s;

            int start = 0;
            int maxLen = 1;

            // Odd length palindrome
            for (int i = 0; i < n; i++) {

                int j = i;
                int k = i;

                while (j >= 0 && k < n && s[j] == s[k]) {

                    if (k - j + 1 > maxLen) {
                        start = j;
                        maxLen = k - j + 1;
                    }

                    j--;
                    k++;
                }
            }

            // Even length palindrome
            for (int i = 0; i < n - 1; i++) {

                int j = i;
                int k = i + 1;

                while (j >= 0 && k < n && s[j] == s[k]) {

                    if (k - j + 1 > maxLen) {
                        start = j;
                        maxLen = k - j + 1;
                    }

                    j--;
                    k++;
                }
            }

            return s.substr(start, maxLen);
    }
};
