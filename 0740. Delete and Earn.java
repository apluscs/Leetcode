class Solution {
    public int deleteAndEarn(int[] nums) {
        TreeMap < Integer, Integer > radix = new TreeMap < > ();  //MUCH slower than typical int[] count
        for (int n: nums) {
            radix.put(n, radix.getOrDefault(n, 0) + 1);
        }
        int used = 0, avoid = 0, prev = -1;
        for (Map.Entry < Integer, Integer > entry: radix.entrySet()) {
            int curr = entry.getKey();
            int count = entry.getValue();
            int temp = Math.max(used, avoid);
            if (curr == prev + 1) {
                used = avoid + count * curr;
                avoid = temp;
            } else {
                used = temp + count * curr;
                avoid = temp;
            }
            prev = curr;
        }
        return Math.max(avoid, used);
    }
}
