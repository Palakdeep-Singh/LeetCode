// Last updated: 8/8/2026, 3:42:38 PM
class Solution {
public:
    string reverseByType(string s) {
        vector <char> vec;
        vector <char> num;
        int j = 0;
        for(int i=0;i<s.size();i++){
            if((s[i] >='0' && s[i] <= '9') || (s[i] >='a' && s[i] <= 'z')){
                num.push_back(s[i]);
            }
            else{
                vec.push_back(s[i]);
            }
        }

        reverse(num.begin(),num.end());
        reverse(vec.begin(),vec.end());
        
        int t=0;
        for(int i=0;i<s.size();i++){
            if((s[i] >='0' && s[i] <= '9') || (s[i] >='a' && s[i] <= 'z')){
                s[i] = num[j++];
            }
            else{
                s[i] = vec[t++];
            }
        }

        return s;
    }
};