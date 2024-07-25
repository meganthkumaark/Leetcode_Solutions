class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        //to store groups of anagrams
        Map<String,List<String>>anagramGroups=new HashMap<>();
        //iterate each string in the input
        for(String str:strs)
        {
            //convert string to a char array and sort it
            char[] charArray=str.toCharArray();
            Arrays.sort(charArray);
            //convert the sorted char array back to string
            String sortedStr=new String(charArray);
            //original string to the crt group in the map
            anagramGroups.computeIfAbsent(sortedStr,k->new ArrayList<>()).add(str);
        }
        //convert the map values to a list of lists
        List<List<String>> result=new ArrayList<>(anagramGroups.values());
        return result;
    }
}