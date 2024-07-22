public class Solution {
    public int maxOperations(String s) {
        int ans = 0, p = 0;
        boolean kit = false;
        List<Integer> hit = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                hit.add(1);
                kit = true;
            }
            if (s.charAt(i) == '0' && kit) {
                hit.add(0);
                kit = false;
            }
        }

        for (int it : hit) {
            if (it == 1) {
                p++;
            } else {
                ans += p;
            }
        }

        return ans;
    }
}