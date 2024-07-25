import java.util.ArrayList;
import java.util.List;

class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> numbers = new ArrayList<>();
        int[] factorial = new int[n];
        StringBuilder sb = new StringBuilder();

        // Create an array of factorial lookup
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        // Create a list of numbers to get indices
        for (int i = 1; i <= n; i++) {
            numbers.add(i);
        }

        // Adjust k to be zero-indexed
        k--;

        for (int i = n; i > 0; i--) {
            int index = k / factorial[i - 1];
            sb.append(numbers.get(index));
            numbers.remove(index);
            k -= index * factorial[i - 1];
        }

        return sb.toString();
    }
}
