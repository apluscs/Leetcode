class Solution {
    public String customSortString(String S, String T) {
        int[] frq = new int[26]; //radix sort
        for (int i = T.length() - 1; i != -1; i--) frq[T.charAt(i) - 'a']++;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i != S.length(); i++) {
            char c = S.charAt(i);
            for (int j = frq[c - 'a']; j != 0; j--) sb.append(c); //piece T back together in order
            frq[c - 'a'] = 0; //essential for last part
        }
        for (int i = 0; i != 26; i++)
            for (int j = frq[i]; j != 0; j--) sb.append((char)('a' + i)); //add any chars whose order wasn't specified in S
        return sb.toString();
    }
}
