class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";

        unordered_map<char, int> targetCount, windowCount;
        for (char c : t)
            targetCount[c]++;

        int requiredCount = targetCount.size();
        int formed = 0, left = 0, right = 0;
        int minLength = INT_MAX, minLeft = 0;

        while (right < s.length()) {
            char currentChar = s[right];
            windowCount[currentChar]++;

            if (targetCount.find(currentChar) != targetCount.end() && windowCount[currentChar] == targetCount[currentChar])
                formed++;

            while (left <= right && formed == requiredCount) {
                int windowLength = right - left + 1;
                if (windowLength < minLength) {
                    minLength = windowLength;
                    minLeft = left;
                }

                char leftChar = s[left];
                windowCount[leftChar]--;

                if (targetCount.find(leftChar) != targetCount.end() && windowCount[leftChar] < targetCount[leftChar])
                    formed--;

                left++;
            }

            right++;
        }

        return (minLength == INT_MAX) ? "" : s.substr(minLeft, minLength);
    }
};