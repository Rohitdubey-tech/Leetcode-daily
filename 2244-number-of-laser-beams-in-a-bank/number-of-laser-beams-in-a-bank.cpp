class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;   
        int total = 0;  

        for (auto& row : bank) {
            int devices = count(row.begin(), row.end(), '1');
            if (devices == 0) continue; 

            total += prev * devices; 
            prev = devices;             
        }

        return total;
    }
};
