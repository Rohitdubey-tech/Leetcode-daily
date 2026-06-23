class Solution {
public:
    string removeKdigits(string num, int k) {

        string result = "";

        for(char ch : num)
        {
            while(!result.empty() &&
                  result.back() > ch &&
                  k > 0)
            {
                result.pop_back();
                k--;
            }

            if(!result.empty() || ch != '0')
            {
                result.push_back(ch);
            }
        }

        while(k > 0 && !result.empty())
        {
            result.pop_back();
            k--;
        }

        return result.empty() ? "0" : result;
    }
};