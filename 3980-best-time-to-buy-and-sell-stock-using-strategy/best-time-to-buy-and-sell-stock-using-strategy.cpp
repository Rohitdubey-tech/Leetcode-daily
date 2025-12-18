class Solution {
public:
    long long solve(int i, int j, vector<long long> &vec, int n)
    {
        long long subarray_sum=0;
        if(i){
            subarray_sum = vec[j]-vec[i-1];
        }else{
            subarray_sum=vec[j];
        }
        long long total_profit = vec[n-1];

        return total_profit - subarray_sum;
    }
    long long solve2(int i, int j, vector<long long> &vec)
    {
        long long ans=0;
        return vec[j]-vec[i-1];
    }
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> orig(n,0);
        for(int i=0;i<n;i++)
        {
            orig[i]=prices[i]*strategy[i];
        }
        vector<long long> orig_pref(n,0);
        orig_pref[0]=orig[0];
        for(int i=1;i<n;i++)
        {
            orig_pref[i]=orig[i]+orig_pref[i-1];
        }

        vector<long long> sell_vec_prefix(n,0); 
        sell_vec_prefix[0]=prices[0];
        for(int i=1;i<n;i++){
            sell_vec_prefix[i]=prices[i]+sell_vec_prefix[i-1];
        }

        long long mxprofit=orig_pref[n-1]; 

        for(int i=0;i<=n-k;i++)
        {
            int start_k = i;  
            int end_k = i+k-1; 

            int start_sell = i+(k/2); 
            int end_sell = end_k; 

            long long ans1 = solve(start_k,end_k,orig_pref,n);
            long long ans2 = solve2(start_sell,end_sell,sell_vec_prefix);

            mxprofit = max(mxprofit,ans1+ans2);
        }

        return mxprofit;

        
    }
};
