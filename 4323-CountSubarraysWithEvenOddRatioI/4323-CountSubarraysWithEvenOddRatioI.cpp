// Last updated: 8/8/2026, 3:42:22 PM
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int even = 0,odd = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            even=0;
            odd=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j] % 2 == 0){
                    even++;
                }
                else{
                    odd++;
                }

                  if(odd == 0){
            continue;
            }
            else{
                if(even*b <= odd * a){
                    total++;
                }
            }
            }

        }

        return total;
    }
};