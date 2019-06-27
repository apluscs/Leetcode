class Solution {
    public int preimageSizeFZF(int K) {
        long low = 0, high = 5000000000 L, min, max; //min=first num with K zeroes
        while (low <= high) {
            long mid = (low + high) / 2;
            long z = numZeroes(mid);
            if (z >= K) high = mid - 1;
            else low = mid + 1;
        }
        min = low;
        low = 0;
        high = 5000000000 L;
        while (low <= high) {
            long mid = (low + high) / 2;
            long z = numZeroes(mid);
            if (z > K) high = mid - 1;
            else low = mid + 1;
        }
        max = high; //= last num with K zeroes
        // System.out.println(min+", "+max);
        return (int)(max - min + 1);
    }

    long numZeroes(long num) { //classic factorial zero problem
        long res = 0, base = 5;
        while (base <= num) { //count number of fives in factorial, which come from powers of 5
            res += num / base; //number of times base goes into factorial
            base *= 5; //multiples of 5^2 are singly counted during multiples of 5, so just add another
        }
        return res;
    }
}
