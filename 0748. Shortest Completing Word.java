class Solution {
    public static int[] primes = new int[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
    public String shortestCompletingWord(String licPlate, String[] words) {
        String res = "aaaaaaaaaaaaaaaa"; //16, more than max bound
        long plate = getProd(licPlate.toLowerCase());
        for (String s: words)
            if (s.length() < res.length() && getProd(s.toLowerCase()) % plate == 0) //this means s has all the letters in licPlate
                res = s;
        return res;
    }

    public static long getProd(String s) {
        long res = 1;
        for (int i = 0; i != s.length(); i++) {
            int c = s.charAt(i) - 'a';
            if (c >= 0 && c <= 25) res *= primes[c];
        }
        return res;
    }

}
