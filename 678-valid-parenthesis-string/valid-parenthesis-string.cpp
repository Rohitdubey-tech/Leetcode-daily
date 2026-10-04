class Solution {
public:
    bool checkValidString(string s) {
        int cnt1 = 0;
        int cnt2 = 0;
        for(auto c : s){
            if(c == '('){
                cnt1++;
                cnt2++;
            }
            else if(c == ')'){
                cnt1--;
                cnt2--;
            }
            else{
                cnt1--;   
                cnt2++;   
            }
            if(cnt2 < 0){
                return false;
            }
            if(cnt1 < 0){
                cnt1 = 0;
            }
        }
        return cnt1 == 0;
    }
};