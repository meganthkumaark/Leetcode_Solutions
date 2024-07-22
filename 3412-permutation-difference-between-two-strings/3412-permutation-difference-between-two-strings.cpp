class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> index_map;
        for (int i = 0; i < s.length(); ++i) {
            index_map[s[i]] = i;
        }

        int permutation_diff = 0;
        for (int i = 0; i < t.length(); ++i) {
            char c = t[i];
            if (index_map.find(c) != index_map.end()) { // Check if character exists in s
                permutation_diff += abs(index_map[c] - i);
            } else { // If character doesn't exist in s, add length of s to permutation_diff
                permutation_diff += s.length();
            }
        }

        return permutation_diff;
    }

};