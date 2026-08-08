class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto val : s) {
            if('(' == val || '[' == val || '{' == val) {
                st.push(val);
            } else if (')' == val || ']' == val || '}' == val) {
                if(')' == val && !st.empty() && st.top() == '(') {
                    st.pop();
                } else if (']' == val && !st.empty() && st.top() == '['){
                    st.pop();
                } else if ('}' == val && !st.empty() && st.top() == '{') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty() == 1 ? true : false;
        
    }
};
