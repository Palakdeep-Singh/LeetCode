// Last updated: 8/8/2026, 3:42:36 PM
class Solution {
public:

    bool isDigitorialPermutation(int n) {
        
        string s = "";
        
        while(n){
            s += n%10 + '0';
            n/=10;
        }

        sort(s.begin(),s.end());
        return s == "1" || s == "2" || s == "145" || s == "04558";
    }
};