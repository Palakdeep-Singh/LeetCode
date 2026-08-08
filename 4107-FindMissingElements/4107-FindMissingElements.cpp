// Last updated: 8/8/2026, 3:42:54 PM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int start = *min_element(nums.begin(),nums.end());
        int end = *max_element(nums.begin(),nums.end());

        vector<int> result;
        unordered_map <int,int> freq;

        for(int i : nums){
            freq[i]++;
        }

        for(int i=start;i<=end;i++){
            if(freq[i] == 0){
                result.push_back(i);
            }
        }

        return result;
    }
};