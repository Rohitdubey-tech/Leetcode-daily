class Solution {
public:
    void buildCombinations(
        int index,
        string &digits,
        string &current,
        vector<string> &mapping,
        vector<string> &result
    ) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = mapping[digits[index] - '0'];
        for (char ch : letters) {
            current.push_back(ch);
            buildCombinations(index + 1, digits, current, mapping, result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current;
        buildCombinations(0, digits, current, mapping, result);
        return result;
    }
};
