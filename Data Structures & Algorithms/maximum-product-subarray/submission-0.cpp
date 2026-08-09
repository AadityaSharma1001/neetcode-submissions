class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int answer = INT_MIN;

        for(int i = 0 ; i < n ; i++) {
            prefix *= nums[i];
            suffix *= nums[n-i-1];

            answer = max(answer,max(prefix,suffix));
            if(nums[i] == 0) prefix = 1;
            if(nums[n-i-1] == 0) suffix = 1;
        }

        return answer;
    }
};
