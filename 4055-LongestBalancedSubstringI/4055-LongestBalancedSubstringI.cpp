// Last updated: 8/8/2026, 3:42:58 PM
class Solution {
public:
    int longestBalanced(string s) {

        int n =  s.size();
        int result = 1;

        for(int i = 0 ;i<n;i++){

            vector<int> vec(26,0);

            for(int j = i;j<n;j++){

            bool check = true;
            vec[s[j]-'a']++;

            for(int t : vec){
                if(t>0 && t != vec[s[j]-'a']){
                    check = false;
                    break;
                }
            }
            if(check){
                result = max(result,j-i+1);
            }
            
            }
        }

        return result;
    }
};