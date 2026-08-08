// Last updated: 8/8/2026, 3:42:25 PM
class Solution {
public:
    int countValidPrefixes(string s) {

        int n = s.size();
        int count_zero = 0;
        int count_one = 0;
        int count = 0;

        for(int i =0;i<n;i++){

            if(s[i] == '0'){
                count_zero++;
            }
            else{
                count_one++;
            }

            if(abs(count_zero-count_one) <=1 ){
                count++;
            }
        }

        return count;
    }
};