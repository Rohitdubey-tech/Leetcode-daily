class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        while(read < chars.size()){
            char current = chars[read];
            int count = 0;
            while(read < chars.size() && current == chars[read]){
                read++;
                count++;
            }
            chars[write] = current;
            write++;

            if(count > 1){
                string cnt = to_string(count);
                for(char c: cnt){
                    chars[write] = c;
                    write++;
                }
            }
        }
        return write;

    }
};