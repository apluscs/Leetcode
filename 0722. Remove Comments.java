class Solution {  //TLE :(
    public List < String > removeComments(String[] source) {
        int si = 0, ci = 0;
        String curr = "";
        List < String > res = new ArrayList < > ();
        while (si != source.length) {
            String s = source[si].substring(ci);
            int k = s.indexOf("//");
            int j = s.indexOf("/*");
            if (k != -1 && (j == -1 || k < j)) {
                String temp = curr + s.substring(0, k);
                if (temp.length() != 0) res.add(temp);
                si++;
                ci = 0;
                curr = "";
            } else if (j != -1 && (k == -1 || j < k)) {
                curr += s.substring(0, j);
                int[] update = search(source, si, j + 2);
                si = update[0];
                ci = update[1];
                // System.out.println("si "+si+", ci "+ci);
            } else {
                String temp = curr + s;
                if (temp.length() != 0) res.add(temp);
                si++;
                ci = 0;
                curr = "";
            }
        }
        return res;
    }
    public static int[] search(String[] source, int i, int j) {
        int[] res = new int[2];
        while (i != source.length) {
            // System.out.println("i "+i+", j "+j);
            String s = source[i].substring(j);
            int k = s.indexOf("*/");
            if (k != -1) return new int[] {
                i,
                k + 2 + j
            };
            i++;
            j = 0;
        }
        return res;
    }
}
