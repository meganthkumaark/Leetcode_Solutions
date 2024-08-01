class Solution {
    public int countSeniors(String[] details) {
        int seniorCount = 0;

        for (String detail : details) {
             String ageString = detail.substring(11, 13);
            int age = Integer.parseInt(ageString);

             if (age > 60) {
                seniorCount++;
            }
        }

        return seniorCount;
    }
}