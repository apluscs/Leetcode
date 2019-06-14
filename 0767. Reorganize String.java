class Solution {
    public String reorganizeString(String str) {
        int N = str.length();
        int[][] frq = new int[26][2]; //(frequnecy, char's int val)
        for (int i = 0; i != N; i++) frq[str.charAt(i) - 'a'][0]++;
        for (int i = 0; i != 26; i++) frq[i][1] = i + 'a'; //char int val
        Arrays.sort(frq, (a, b) - > b[0] - a[0]); //descendingly, most frequent are dealt with first

        if (frq[0][0] > (N + 1) / 2) return ""; //if the most frequent can fit, everyone can too; if it can't, we can't reorganize
        int ind = -1, count = 0;
        char c = ' '; //bogus
        char[] res = new char[N];
        for (int i = 0; i < N; i += 2) { //even indices
            if (count == 0) { //fill in all instances of this char we need to
                ind++; //new char to fill in
                c = (char) frq[ind][1];
                count = frq[ind][0];
            }
            res[i] = c;
            count--;
        }
        for (int i = 1; i < N; i += 2) { //odd indices
            if (count == 0) {
                ind++;
                c = (char) frq[ind][1];
                count = frq[ind][0];
            }
            res[i] = c;
            count--;
        }
        return new String(res);
    }
}
