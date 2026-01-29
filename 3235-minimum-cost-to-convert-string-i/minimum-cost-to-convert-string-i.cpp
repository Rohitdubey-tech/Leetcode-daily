class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = source.length() , m =cost.size();
        vector<vector<int>> adjMat(26,vector<int>(26,INT_MAX));
        
        for(int i=0;i<26;i++){
            adjMat[i][i]=0;
        }
        for(int i=0;i<m;i++){
            adjMat[(original[i])-'a'][(changed[i])-'a']= min(adjMat[(original[i])-'a'][(changed[i])-'a'],cost[i]);
        }

        warshall(adjMat);

        long long res = 0LL;
        for(int k=0;k<n;k++){
            int s= source[k]-'a', d=target[k]-'a';
            if(s==d) continue;
            if(adjMat[s][d]==INT_MAX) return -1;
            else res+=adjMat[s][d];
        }
        return res;
    }

    void warshall(vector<vector<int>>& adjMat){
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adjMat[i][k]!= INT_MAX && adjMat[k][j]!= INT_MAX){
                        adjMat[i][j]=min(adjMat[i][j],adjMat[i][k]+adjMat[k][j]);
                    }
                }
            }
        }
    }
};