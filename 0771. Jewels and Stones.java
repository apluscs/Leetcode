class Solution {
    public int numJewelsInStones(String J, String S) {
        boolean[] jew = new boolean[70]; //lessen memory a bit
        int res = 0;
        for (int i = J.length() - 1; i != -1; i--)
            jew[J.charAt(i) - 'A'] = true;
        for (int i = S.length() - 1; i != -1; i--)
            if (jew[S.charAt(i) - 'A']) res++;
        return res;
    }
}
