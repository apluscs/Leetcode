class Solution {
    public List < Integer > selfDividingNumbers(int left, int right) {
        List < Integer > res = new ArrayList < > ();
        for (int i = left; i <= right; i++) {
            int num = i;
            boolean flag = true;
            while (num != 0) {
                if (num % 10 == 0 || i % (num % 10) != 0) {
                    flag = false;
                    break;
                }
                num /= 10;
            }
            if (flag) res.add(i);
        }
        return res;
    }
}
