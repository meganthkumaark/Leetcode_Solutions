class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int[] countB = new int[n];
        int[] countA = new int[n];
        
        countB[0] = (s.charAt(0) == 'b') ? 1 : 0;
        countA[n - 1] = (s.charAt(n - 1) == 'a') ? 1 : 0;
        
        // Count number of 'b's up to each index
        for (int i = 1; i < n; i++) {
            countB[i] = countB[i - 1] + (s.charAt(i) == 'b' ? 1 : 0);
        }
        
        // Count number of 'a's from each index to the end
        for (int i = n - 2; i >= 0; i--) {
            countA[i] = countA[i + 1] + (s.charAt(i) == 'a' ? 1 : 0);
        }
        
        int minDeletions = Math.min(countB[n - 1], countA[0]);
        for (int i = 0; i < n - 1; i++) {
            minDeletions = Math.min(minDeletions, countB[i] + countA[i + 1]);
        }
        
        return minDeletions;
    }
}
