class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        if (numerator == 0) return "0";
        string result;
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }
        long long num = llabs(numerator);
        long long den = llabs(denominator);
        result += to_string(num / den);
        long long remainder = num % den;
        if (remainder == 0) return result;
        result += ".";
        unordered_map<long long, int> remainderMap;
        while (remainder != 0) {
            if (remainderMap.find(remainder) != remainderMap.end()) {
                int index = remainderMap[remainder];
                result.insert(index, "(");
                result += ")";
                break;
            }
            remainderMap[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        return result;
    }
};
