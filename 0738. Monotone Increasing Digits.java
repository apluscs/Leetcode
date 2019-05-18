class Solution {
    public int monotoneIncreasingDigits(int N) {
        if (N < 10) return N;
        int[] digs = new int[10];
        int i = 9;
        while (N != 0) {
            digs[i--] = N % 10;
            N /= 10;
        }
        // System.out.println(Arrays.toString(digs));
        i++; //now at the first digit of the number
        while (i != 9) {
            if (digs[i + 1] < digs[i]) { //faulty
                int j = i;
                while (j != 0 && digs[j - 1] == digs[j]) j--;
                digs[j++]--; //on the first digit of the "monotone equal sequence (ex. 7776)"
                while (j != 10) digs[j++] = 9; //sets all others to 9
                break;
            }
            i++;
            // System.out.println(Arrays.toString(digs));
        }
        int res = 0;
        for (int d: digs) res = res * 10 + d;
        return res;
    }
}
