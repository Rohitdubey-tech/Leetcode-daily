class Solution {
public:
    string decodeString(string s) {
        stack<int>numStack;
        stack<string>strStack;
        string curr = "";
        int num = 0;
        for(char c : s){
            if(isdigit(c)){
                num = num * 10 + ( c- '0');
            }
            else if(c == '['){
                numStack.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            }
            else if(c == ']'){
                int k = numStack.top();
                numStack.pop();
                string prev = strStack.top();
                strStack.pop();
                for(int i=0; i<k; i++){
                    prev += curr;
                }
                curr = prev;
            }
            else{
                curr += c;
            }
        }
        return curr;
    }
};