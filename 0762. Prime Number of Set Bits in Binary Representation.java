class Solution {
    boolean[] isPrime = new boolean[] { false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false };
    public int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i != R + 1; i++) {
            int num = i, ones = 0;
            while (num != 0) {
                if ((num & 1) == 1) ones++; //count number of ones in binary representation
                num >>= 1;
            }
            if (isPrime[ones]) res++;
        }
        return res;
    }
}
