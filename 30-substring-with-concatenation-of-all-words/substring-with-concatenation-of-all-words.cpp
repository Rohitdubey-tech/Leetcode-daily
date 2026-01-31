class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.length(), m = words.size();
        if (n == 0 || m == 0) return ans;
        int l = words[0].length();

        unordered_map<string, int> wordCount;
        for (const string& w : words) wordCount[w]++;

        for (int i = 0; i < l; i++) {
            unordered_map<string, int> seen;
            int left = i, count = 0;
            for (int j = i; j <= n - l; j += l) {
                string sub = s.substr(j, l);
                if (wordCount.count(sub)) {
                    seen[sub]++;
                    count++;
                    while (seen[sub] > wordCount[sub]) {
                        string leftWord = s.substr(left, l);
                        seen[leftWord]--;
                        count--;
                        left += l;
                    }
                    if (count == m) ans.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = j + l;
                }
            }
        }
        return ans;
    }
};