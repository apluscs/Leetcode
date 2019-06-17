class Solution {
    int N;
    List < String > res;
    public List < String > letterCasePermutation(String str) {
        StringBuilder sb = new StringBuilder(str); //easier to modify specific pieces 
        N = str.length();
        res = new ArrayList < > ();
        helper(sb, 0);
        return res;
    }

    void helper(StringBuilder sb, int ind) {
        if (ind == N) {
            res.add(sb.toString());
            return;
        }
        char c = sb.charAt(ind);
        helper(sb, ind + 1); //default version
        if (c >= '0' && c <= '9') return; //don't need to modify anything, just continue

        if (c >= 'a') { //must be lowercase since a-z comes after A-Z in ASCII table
            sb.setCharAt(ind, (char)(c + 'A' - 'a')); //change to upper case
            helper(sb, ind + 1);
            sb.setCharAt(ind, c); //change back to original
        } else { //uppercase
            sb.setCharAt(ind, (char)(c - 'A' + 'a')); //change to lowercase
            helper(sb, ind + 1);
            sb.setCharAt(ind, c);
        }
    }
}
