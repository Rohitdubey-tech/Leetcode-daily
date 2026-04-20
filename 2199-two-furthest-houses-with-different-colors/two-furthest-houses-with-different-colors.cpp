class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int color = colors[0];
        int i=0;
        while(colors[i]==colors[n-1-i] && colors[i]==color)i++;
        return n-1-i;
    }
};