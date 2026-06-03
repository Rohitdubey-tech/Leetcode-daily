class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ldu,
                           vector<int>& wst, vector<int>& wdu) {

        int ans = INT_MAX, mln = INT_MAX, mnw = INT_MAX;

        for (int i = 0; i < lst.size(); i++)
            mln = min(mln, lst[i] + ldu[i]);

        for (int i = 0; i < wst.size(); i++)
            ans = min(ans, max(mln, wst[i]) + wdu[i]);

        for (int i = 0; i < wst.size(); i++)
            mnw = min(mnw, wst[i] + wdu[i]);

        for (int i = 0; i < lst.size(); i++)
            ans = min(ans, max(mnw, lst[i]) + ldu[i]);

        return ans;
    }
};
