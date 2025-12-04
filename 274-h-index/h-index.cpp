class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h =0;
        for(int i=0; i<citations.size(); i++){
            int papers = i+1;
            if(citations[i]>=papers){
                h=papers;

            }
            else{
                break;
            }
        }
        return h;
    }
};