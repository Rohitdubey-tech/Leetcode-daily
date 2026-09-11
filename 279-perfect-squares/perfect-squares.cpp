class Solution {
public:
    int numSquares(int n) {
     queue<int>q;
     vector<bool>visited(n+1, false);
     q.push(0);
     visited[0] = true;
     int level = 0;
     while(!q.empty()){
        int size = q.size();
        while(size--){
            int current = q.front();
            q.pop();
            if(current == n){
                return level;
            }
            for(int i=1; i*i<=n; i++){
                int next = current + i*i;
                if(next <=n && !visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        level++;
     }  
     return level; 
    }
};