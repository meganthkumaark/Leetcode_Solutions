
class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        int totalOnes = 0;
        for (int num : nums) {
            totalOnes += num;
        }

        if (totalOnes == 0) {
            return 0;
        }

        int maxOnesInWindow = 0;
        int currentOnes = 0;
            for (int i = 0; i < 2 * n; i++) {
            currentOnes += nums[i % n];

            if (i >= totalOnes) {
                currentOnes -= nums[(i - totalOnes) % n];
            }

            maxOnesInWindow = Math.max(maxOnesInWindow, currentOnes);
        }
        return totalOnes - maxOnesInWindow;
    }
}