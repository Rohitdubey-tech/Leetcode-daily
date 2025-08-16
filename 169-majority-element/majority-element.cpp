// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             int count = 0;
//             for(int j=0; j<n; j++){
//                 if(nums[j]==nums[i]){
//                     count++;
//                 }
//             }
//             if(count>(n/2)){
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;   
            }
            count += (num == candidate ? 1 : -1);
        }
        return candidate;  
    }
};

