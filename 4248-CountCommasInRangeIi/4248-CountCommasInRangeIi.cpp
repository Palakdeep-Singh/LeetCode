// Last updated: 8/8/2026, 3:42:23 PM
class Solution {
public:
    long long countCommas(long long n) {

        long long totalCount = 0;
        long long comma_values[] = {
            1000LL,
            1000000LL,
            1000000000LL,
            1000000000000LL,
            1000000000000000LL,
            1000000000000000000LL
        };

        for(int i=1;i<=5;i++){

            long long start = comma_values[i-1];
            long long end = comma_values[i]-1;

            if(start>n){
                break;
            }

            long long count = min(n,end)-start+1;
            totalCount += (long long)i*count;
        }
        return totalCount;
    }
};