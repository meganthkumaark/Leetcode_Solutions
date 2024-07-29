class Solution {
    public int firstUniqChar(String s) {
        //create an to store the alphabets 
        int[] charFrequency=new int[26];
        //count the frequency of each character in the string
        for(char c:s.toCharArray())
        {
            charFrequency[c - 'a']++;
        }
        //index of the first unique character
        for(int i=0;i<s.length();i++)
        {
            if(charFrequency[s.charAt(i)-'a']==1)
            {
                return i;
            }
        }
        return -1;
    }
}