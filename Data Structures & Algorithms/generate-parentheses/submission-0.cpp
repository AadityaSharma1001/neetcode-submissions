class Solution {
private:
    void solve(int count1, int count2, int& n, string& temp, vector<string>& ans) {
        if(count1 == n && count2 == n) {
            ans.push_back(temp);
            return ;
        }

        if(count1 < n) {
            temp += '(';
            solve(count1+1, count2, n, temp, ans);
            temp.pop_back();
        }
        if(count2 < n && count1 > count2) {
            temp += ')';
            solve(count1, count2+1, n, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==1) {
            ans.push_back("()");
            return ans;
        }

        string temp = "";
        
        solve(0, 0, n, temp, ans);
        return ans;
    }
};
