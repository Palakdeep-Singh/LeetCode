// Last updated: 8/8/2026, 3:42:37 PM
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        
        int player1 = 0, player2 = 0;

        int n = nums.size();

        bool player1_play = true; // start with Player1.

        for(int i=0;i<n;i++){
            if(player1_play){
                if((i+1)%6 == 0){
                   if(nums[i]%2 != 0){
                    player1 += nums[i];
                   }
                   else{
                    player1_play = !player1_play;
                    player2 += nums[i];
                   }
                }
                else{
            if(nums[i]%2 == 0){
                player1 += nums[i];
            }
            else{
                player1_play = !player1_play;
                player2 += nums[i];
            }
                }
            }
            else{
                if((i+1)%6 == 0){
                   if(nums[i]%2 != 0){
                    player2 += nums[i];
                   }
                   else{
                    player1_play = !player1_play;
                    player1 += nums[i];
                   }
                }
                else{
                    if(nums[i]%2 == 0){
                        player2 += nums[i];
                    }
                    else{
                        player1_play = !player1_play;
                        player1 += nums[i];
                    }
                }
            }
        }

        return player1-player2;
    }
};