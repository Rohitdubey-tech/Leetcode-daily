class Solution {
public:
    bool change(string a, string b){
        int cnt = 0;
        for(int i=0; i<a.size(); i++)
            if(a[i]!=b[i])
                cnt++;
        return cnt <=2;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        int n = queries.size();
        int m = dictionary.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(change(queries[i], dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};