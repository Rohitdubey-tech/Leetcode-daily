class DSU {
    public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findParent(int a) {
        if(a == parent[a]) return a;
        return parent[a] = findParent(parent[a]);
    }
    void unite(int a, int b) {
        a = findParent(a);
        b = findParent(b);
        if(a == b) return;
        if(rank[a] > rank[b]) {
            parent[b] = a;
        } else if(rank[b] > rank[a]) {
            parent[a] = b;
        } else {
            parent[a] = b;
            rank[b]++;
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU ds(n);

        for(int i = 1; i < nums.size(); i++) {
            if(abs(nums[i] - nums[i - 1]) <= maxDiff) {
                ds.unite(i, i - 1);
            }
        }
        vector<bool> ans;
        for(auto &q:queries) {
            int u = ds.findParent(q[0]);
            int v = ds.findParent(q[1]);
            if(u == v) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};