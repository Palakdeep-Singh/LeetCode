// Last updated: 8/8/2026, 3:42:26 PM
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {

        long long final_ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long gcd_ = gcd(nums[i],nums[j]);
                long long ans = (1LL * nums[i]*nums[j])/(gcd_*gcd_);
                final_ans = max(ans,final_ans);
            }
        }


        return final_ans;
    }
};