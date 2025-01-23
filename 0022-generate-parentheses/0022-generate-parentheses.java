class Solution {
    public List<String> generateParenthesis(int n) {
        List <String> resu = new ArrayList<>();
        backtrack(resu,"",0,0,n);
        return resu;
    }

    private void backtrack(List<String> resu,String current, int open, int close, int n){
        if(current.length() == n*2){
            resu.add(current);
            return;
        }

        if(open < n){
            backtrack(resu,current + "(" , open+1, close, n);
        }
        if(close < open){
            backtrack(resu, current + ")", open, close+1, n);
        }
    }
}