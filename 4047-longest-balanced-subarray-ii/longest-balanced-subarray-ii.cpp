const int SQ = 200;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), blocks = (n + SQ - 1) / SQ;
        int ans = 0;

        vector<int> blockLevelAdd(blocks, 0);
        vector<int> accum(n, 0);
        vector<vector<int>> blockLeft(blocks, vector<int>(n * 2 + 1, (int)1e9));
        unordered_map<int, int> last;

        for (int r = 0; r < n; r++) {
            int l = last.count(nums[r]) ? last[nums[r]] + 1 : 0;
            int delta = nums[r] % 2 ? -1 : +1;

           
            int lblk = l / SQ, rblk = r / SQ;

            for (int blk = lblk; blk <= rblk; blk++) {
             
                if (blk == lblk || blk == rblk) {
                    for (int i = min(blk * SQ + SQ - 1, n - 1); i >= blk * SQ; i--)
                        blockLeft[blk][accum[i] + n] = 1e9;
                    
                    for (int i = min(blk * SQ + SQ - 1, n - 1); i >= blk * SQ; i--) {
                        accum[i] += (i >= l && i <= r) ? delta : 0;
                        blockLeft[blk][accum[i] + n] = i;
                    }
                }
             
                else 
                    blockLevelAdd[blk] += delta;
            }
        
            for (int blk = 0; blk <= rblk; blk++)
                ans = max(ans, r - blockLeft[blk][-blockLevelAdd[blk] + n] + 1);

            last[nums[r]] = r;
        }
        return ans;
    }
};