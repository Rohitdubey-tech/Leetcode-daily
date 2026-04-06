class Solution {
public:
    void maxdist1(int& maxdist,int x, int y){
        int dist = x*x + y*y;
        if(maxdist < dist){
            maxdist = dist;
        }
    }
    bool finding(unordered_set<long long>& st,int x,int y){
        long long key = ((long long)x << 32) | (y & 0xffffffff);
        return st.count(key);
    }
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int move = 0;
        int n = commands.size();
        int maxdist = 0;

        unordered_set<long long> st;
        for (auto &p : obstacles) {
            long long key = ((long long)p[0] << 32) | (p[1] & 0xffffffff);
            st.insert(key);
        }

        for(int i = 0; i < n; i++){
            
            if(commands[i] == -2){
                move = (move + 3) % 4;
            }
            else if(commands[i] == -1){
                move = (move + 1) % 4;
            }
            else {
                for(int step = 0; step < commands[i]; step++){
                    
                    if(move == 0 && !finding(st, x, y+1)) y++;
                    else if(move == 1 && !finding(st, x+1, y)) x++;
                    else if(move == 2 && !finding(st, x, y-1)) y--;
                    else if(move == 3 && !finding(st, x-1, y)) x--;
                    else break; 

                    maxdist1(maxdist, x, y);
                }
            }
        }

        return maxdist;
    }
};