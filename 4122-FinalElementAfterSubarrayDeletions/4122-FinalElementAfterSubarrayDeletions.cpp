// Last updated: 8/8/2026, 3:42:51 PM
class Solution {
public:
    int finalElement(vector<int>& nums) {

       return max(nums[0],nums[nums.size()-1]);
    }
};