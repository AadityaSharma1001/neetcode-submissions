class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        int n = s.length();
        for(int i = 0 ; i < n ; i++) {
            if('(' == s[i]) {
                st.push({s[i], i});
            } else if(')' == s[i]) {
                if(!st.empty() && st.top().first == '(') {
                    st.pop();
                } else {
                    st.push({s[i], i});
                }
            }
        }

        unordered_set<int> invalid;
        while (!st.empty()) {
            invalid.insert(st.top().second);
            st.pop();
        }

        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            if (invalid.find(i) == invalid.end()) {
                result += s[i];
            }
        }

        return result;

    }
};
