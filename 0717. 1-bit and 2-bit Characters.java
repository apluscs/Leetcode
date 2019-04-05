class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0, N = bits.length;
        while (i < N) {
            if (i == N - 1) return true; //successfully reached the end 0
            if (bits[i] == 1) i += 2; //skips over 0's if it's a 1
            else i++;
        }
        return false;
    }
}
