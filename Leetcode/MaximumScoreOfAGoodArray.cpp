class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k;
        int min_val = nums[k];
        int ans = min_val;

        while(left > 0 || right < nums.size()-1){
            if(left == 0 || (right < nums.size() - 1  && nums[right + 1 ] > nums[left - 1]))
                right++;
            else
                left--;
            
            min_val = min({min_val,nums[left],nums[right]});
            ans = max(ans, min_val * ( right - left + 1 ));
        }
        return ans;

    }
};