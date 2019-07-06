class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int lns = 0, curr = 0;
        for (char c: S.toCharArray()) {
            curr += widths[c - 'a'];
            if (curr > 100) {
                curr = widths[c - 'a'];
                lns++;
            }
        }
        return new int[] { lns + 1, curr }; //only when lns goes over 100 do we increment, need to count partial last line
    }
}
