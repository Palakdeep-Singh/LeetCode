// Last updated: 8/8/2026, 3:42:27 PM
class Solution {
public:
    int countCommas(int n) {

       int start = 1000;

        if(n<1000){
            return 0;
        }

        return n-start+1;
    }
};