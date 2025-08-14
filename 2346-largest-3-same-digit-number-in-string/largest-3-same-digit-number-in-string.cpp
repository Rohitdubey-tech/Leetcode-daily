class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        for(int i=0; i<=n-3; i++){
            if(num[i]==num[i+1] && num[i+1]==num[i+2]){
                string current = num.substr(i,3);
                if(ans.empty() || current > ans){
                    ans = current;
                }
            }
        }
        return ans;
    }
};