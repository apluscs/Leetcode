class Solution {
    public boolean rotateString(String A, String B) { //KMP algo turned this easy problem into a super hard one :/
        if (A.length() != B.length()) return false;
        if (A.length() == 0) return true; //A.length must = B.length
        char[] patt = B.toCharArray();
        int[] inds = new int[patt.length];
        int anc = 0;
        for (int i = 1; i < patt.length; i++) {
            if (patt[anc] == patt[i]) { //patt[i] means the last patt[i] elem from i are the first patt[i] elem of patt, just continue searching at patt[i] since everything before that is alr found
                inds[i] = inds[i - 1] + 1;
                anc++;
                continue;
            }
            while (anc != 0 && patt[anc] != patt[i]) anc = inds[anc - 1]; //jump back until we find a compatible prefix
            if (patt[anc] == patt[i]) inds[i] = inds[anc] + 1; //new prefix to match with
            else inds[i] = 0; //no match with anything
        } //inds should be complete
        // System.out.println(Arrays.toString(inds));

        char[] str = (A + A).toCharArray();
        anc = 0;
        for (int i = 0; i < str.length; i++) {
            char c = str[i];
            while (anc != 0 && c != patt[anc]) anc = inds[anc - 1]; //if it's a match, this is skipped; otherwise it matches the last few chars with a prefix and continues the search after this prefix
            if (patt[anc] == c) anc++; //get ready to test next char
            if (anc == patt.length) return true; //matched patt fully
        }

        return false;
    }
}
