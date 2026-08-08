class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString = "";
        int index = 0;
        for(auto line : strs) {
            for(auto c : line) {
                encodedString += c+32;
            }

            encodedString += '.';
        }

        return encodedString;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string temp = "";
        for(auto c : s) {
            if(c == '.') {
                strs.push_back(temp);
                temp = "";
                continue;
            }
            temp += c-32;
        }

        return strs;
    }
};
