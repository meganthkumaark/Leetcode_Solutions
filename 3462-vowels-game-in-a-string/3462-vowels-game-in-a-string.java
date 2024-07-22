public class Solution {
    public boolean doesAliceWin(String str) {
        int counter = 0;
        String vowels = "aeiou";

        for (int i = 0; i < str.length(); i++) {
            if (vowels.indexOf(str.charAt(i)) != -1) {
                counter++;
            }
        }

        return counter != 0;
    }
}