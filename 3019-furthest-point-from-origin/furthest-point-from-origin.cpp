class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0, u = 0;
        for (char c : moves) {
            if (c == 'L')
                l++;
            if (c == 'R')
                r++;
            if (c == '_')
                u++;
        }
        if (l >= r) {
            return abs(l + u - r);
        }

        return abs(r + u - l);
    }
};