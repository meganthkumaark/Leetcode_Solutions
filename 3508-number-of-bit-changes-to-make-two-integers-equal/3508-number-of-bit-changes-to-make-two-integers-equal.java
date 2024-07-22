public class Solution {
    public int minChanges(int n, int k) {
        int count = 0;
        for (int i = 31; i >= 0; i--) {
            if ((n & (1 << i)) == 0 && (k & (1 << i)) != 0) {
                return -1;
            }
            if ((n & (1 << i)) != 0 && (k & (1 << i)) == 0) {
                count++;
            }
        }
        return count;
    }
}