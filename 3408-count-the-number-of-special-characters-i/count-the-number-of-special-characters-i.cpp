class Solution {
public:
    int numberOfSpecialChars(string word) {
     unordered_set<char>lower;
     unordered_set<char>upper;
     for(char ch: word){
        if(islower(ch)){
            lower.insert(ch);
        }
        else{
            upper.insert(ch);
        }
     }   
     int count = 0;
     for(char ch : lower){
        if(upper.count(toupper(ch))){
            count++;
        }
     }
     return count;
    }
};