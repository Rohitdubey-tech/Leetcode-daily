class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int index = 0;
        int n = chars.size();
        while(i< n){
            char ch = chars[i];
            int count = 0;
            while(i < n && chars[i] == ch){
                count++;
                i++;
            }
            chars[index] = ch;
            index++;
            if(count > 1){
                string cnt = to_string(count);
                for(char c : cnt){
                    chars[index] = c;
                    index++;
            }
            }
        }
        return index;
    }
};
