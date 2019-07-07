class Solution {
    public int expressiveWords(String str, String[] words) {
        List < int[] > chars = new ArrayList < > ();
        int i = 0, N = str.length(), res = 0;
        while (i != N) {
            char c = str.charAt(i);
            int ct = 0;
            while (i != N && str.charAt(i) == c) {
                ct++;
                i++;
            }
            chars.add(new int[] {
                c,
                ct
            }); //char, how many in a row
        }
        // for(int[] c:chars) System.out.println(Arrays.toString(c));
        for (String w: words) res += judge(chars, w); //1 if stretchable, 0 if not
        return res;

    }
    int judge(List < int[] > chars, String w) {
        int i = 0, N = w.length(), j = 0;
        while (i != N && j != chars.size()) {
            char c = w.charAt(i);
            int ct = 0;
            while (i != N && w.charAt(i) == c) {
                ct++;
                i++;
            }
            int[] frq = chars.get(j++); //wrong char, word has too many chars(can't shrink)
            if (frq[0] != c || ct > frq[1] || frq[1] == 2 && ct < 2) return 0; //word can only stretch to 3+ chars
        }
        if (i != N || j != chars.size()) return 0; //#sequences must match - only when i reaches end of w and j reaches the last sequence of chars at the end
        return 1;
    }
}
