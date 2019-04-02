class Solution {
    public static char[][] vals=new char[][]{{' '},{'*'},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};  //quick conversion
    public static List < String > res;
    public static int N;
    public static String digits;
    public List < String > letterCombinations(String dig) {
        res = new ArrayList < > ();
        digits = dig;
        N = digits.length();
        if (N == 0) return res;
        helper(new StringBuilder(), 0);
        return res;
    }
    public void helper(StringBuilder sb, int ind) { //dfs
        if (ind == N) {
            res.add(sb.toString());
            return;
        }
        int d = digits.charAt(ind) - '0';
        for (int i = vals[d].length - 1; i != -1; i--) {
            sb.append(vals[d][i]);
            helper(sb, ind + 1);
            sb.deleteCharAt(ind); //remove last char added so we can try all others
        }
    }
}
