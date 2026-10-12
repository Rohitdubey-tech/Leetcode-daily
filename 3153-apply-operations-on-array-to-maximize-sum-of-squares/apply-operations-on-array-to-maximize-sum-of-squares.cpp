#define MOD ((long long)(1e9)+7)

class Solution {
public:
    std::vector<int> intToBits(int num) {
        std::vector<int> bits;
        int maxIntBits = 32;
        for (int i = 0; i < maxIntBits; ++i)
            bits.push_back(0);
        for (int i = 0; i < maxIntBits; ++i) {
            int bit = (num >> i) & 1;
            bits[i] = (bit);
        }
        reverse(bits.begin(), bits.end());
        return bits;
    }
    
    int maxSum(vector<int>& nums, int k) {
        vector<vector<int>> bits;
        int intsz = 32;
        for(auto num: nums) bits.push_back(intToBits(num));
        vector<vector<int>> surplus(nums.size()+1, vector<int> (intsz));
        vector<vector<int>> deficit(nums.size()+1, vector<int> (intsz));
        
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < intsz; ++j)
                surplus[i+1][j] = surplus[i][j] + bits[i][j];
        }
        for(int i = nums.size()-1; i >= 0; --i) {
            for(int j = 0; j < intsz; ++j)
                deficit[i][j] = deficit[i+1][j] + (bits[i][j] == 0 ? 1 : 0);
        }
        long long ans = 0;
        for(int i = nums.size()-1, a = 0; a < k; ++a, --i) {
            long long num = 0;
            for(int j = 0; j < intsz; ++j) {
                if(surplus[i+1][j] > deficit[i+1][j])
                    num += pow(2, intsz-j-1);
            }
            cout<<num<<endl;
            ans = (ans + (num*num)%MOD)%MOD;
        }
        return ans;
    }
};