class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> rows(numRows);
        for(int i=0, row =0, step =1; i<s.size(); i++ ){
            rows[row] += s[i];
            if(row == 0) step =1;
            if(row == numRows-1) step = -1;
            row += step;
        }
        string result;
        for(auto r:rows){
            result += r;
        }
        return result;
        
    }
};