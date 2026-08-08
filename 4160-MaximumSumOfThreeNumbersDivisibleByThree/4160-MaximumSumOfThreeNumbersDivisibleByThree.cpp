// Last updated: 8/8/2026, 3:42:43 PM
class Solution {
public:

  
    int maximumSum(vector<int>& nums) {

        vector <int> a,b,c;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0){
                a.push_back(nums[i]);
            }
            else if(nums[i]%3==1){
                b.push_back(nums[i]);
            }
            else{
                c.push_back(nums[i]);
            }
        }

        sort(a.rbegin(),a.rend());
        sort(b.rbegin(),b.rend());
        sort(c.rbegin(),c.rend());

        int ans = 0;
        if(a.size()>=3){
            ans = max(ans,a[0]+a[1]+a[2]);
        }

        if(b.size() >=3){
            ans = max(ans,b[0]+b[1]+b[2]);
        }
        if(c.size()>=3){
            ans = max(ans,c[0]+c[1]+c[2]);
        }

        if(!a.empty() && !b.empty() && !c.empty()){
            ans = max(ans,a[0]+b[0]+c[0]);
        }

        return ans;
    }
};