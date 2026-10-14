class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos){
            int pos = s.find(part);
            s.erase(pos, part.size());
        }
        return s;
    }
};