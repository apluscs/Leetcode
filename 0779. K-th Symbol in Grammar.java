class Solution {
    public int kthGrammar(int N, int K) {
        return Integer.bitCount(K - 1) & 1; //N doesn't matter because every row is a continuation of the previous
    }
}
