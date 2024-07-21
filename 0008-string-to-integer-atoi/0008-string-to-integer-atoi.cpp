#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        int MAX_INT = INT_MAX;
        int MIN_INT = INT_MIN;

        int i = 0;
        int n = s.size();
        int sign = 1;
        long result = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (result > (MAX_INT - digit) / 10) {
                return (sign == 1) ? MAX_INT : MIN_INT;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};
