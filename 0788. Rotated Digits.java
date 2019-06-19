class Solution {
    public int rotatedDigits(int N) {
        int num = 2, res = 0;
        while (num <= N) {
            if (isValid(num)) res++;
            num++;
            // System.out.println(num+", "+pow);
        }
        return res;
    }

    boolean isValid(int num) {
        boolean flag = false; //we just need to find at least 2,5,6,9 AND no 3,4,7. All 1's and 0's won't work
        while (num != 0) {
            int mod = num % 10;
            if (mod == 3 || mod == 4 || mod == 7) return false;
            else if (mod == 2 || mod == 5 || mod == 6 || mod == 9) flag = true;
            num /= 10;
        }
        return flag;
    }
}
