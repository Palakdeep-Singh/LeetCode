// Last updated: 8/8/2026, 3:42:40 PM
class Solution {
public:
    int countMonobit(int n) {
        
        // mono bit means all bits are 1 or 0.
        int count = 1;
        for(int i=1;i<=n;i++){
            if((i & (i+1)) == 0){
                count++;
            }
        }
        return count;
    }
};