class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int n = s.size();

        unordered_map<string, int> freq;
        for (auto &w : words) freq[w]++;

        for (int i = 0; i < wordLen; i++) {
            unordered_map<string, int> window;
            int left = i;
            int count = 0;

            for (int right = i; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);

                if (freq.count(word)) {
                    window[word]++;
                    count++;

                    while (window[word] > freq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};