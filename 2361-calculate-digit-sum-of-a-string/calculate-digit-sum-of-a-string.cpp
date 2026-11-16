class Solution {
public:
    string digitSum(string s, int k) {
        while (static_cast<int>(s.size()) > k) {
            string next;
            next.reserve(s.size() / k + 1);
            for (size_t start = 0; start < s.size(); start += k) {
                size_t end = min(start + static_cast<size_t>(k), s.size());
                int groupSum = 0;
                for (size_t i = start; i < end; ++i) {
                    groupSum += s[i] - '0';
                }
                next += to_string(groupSum);
            }
            s = move(next);
        }
        return s;
    }
};