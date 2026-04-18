class Solution {
public:
    bool allZero(vector<int>counter){
        for(int &i : counter){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size();
        if(p.size()>n) return ans;;
        vector<int> counter(26, 0);
        for(char c : p){
            counter[c-'a']++;
        }
        int i =0; 
        int j =0;
        int k = p.size();
        while(j<n){
            counter[s[j]-'a']--;
            if(j-i+1 == k){
                if(allZero(counter)){
                    ans.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};