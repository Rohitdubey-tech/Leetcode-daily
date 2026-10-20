class Solution {
public:
    bool check(vector<int>& arr) {

        vector<int> v = arr;

        for (int i : arr) {
            v.push_back(i);
        }

        int count = 1;

        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[i - 1]) {
                count = 1;
            } else {
                count++;
            }

            if (count >= arr.size()) {
                return true;
            }
        }

        return false;
    }
    int sortableIntegers(vector<int>& nums) {

        vector<int> divisors;
        int n = nums.size();

        if(n==1){
            return 1;
        }
        divisors.push_back(1);
        divisors.push_back(n);

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {

                divisors.push_back(i);

                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }

        int ans = 0;

        for (int k : divisors) {

            vector<int> temp;
            bool flag = true;

            int prevMax = -1;
            int prevMin = 1e9;

            int currMax = nums[0];
            int currMin = nums[0];

            for (int i = 0; i < n; i++) {
                temp.push_back(nums[i]);
                currMax = max(currMax, nums[i]);
                currMin = min(currMin, nums[i]);

                if ((i + 1) % k == 0 ) {

                    if (!check(temp) || currMin < prevMax) {
                        flag = false;
                        temp.clear();
                        break;
                    }

                    temp.clear();
                    prevMin = currMin;
                    prevMax = currMax;

                    currMax = -1;
                    currMin = 1e9;
                }
            }

            if (flag) {
                ans += k;
            }
        }

        return ans;
    }
};