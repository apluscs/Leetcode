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

class Solution {
    public int deleteAndEarn(int[] nums) {  //MUCH faster
        int[] radix = new int[10001];
        for (int n: nums) radix[n]++; //radix sort
        int used = 0, avoid = 0, prev = -1; //used=max profit if you took prev, avoid=max profit if you didn't
        for (int i = 1; i != 10001; i++) {
            if (radix[i] == 0) continue; //only process vals present in nums
            int temp = Math.max(used, avoid);
            if (i == prev + 1) used = avoid + radix[i] * i; //previous "used" value deleted i, so you must add to avoid
            else used = temp + radix[i] * i; //just add to the max you can get
            avoid = temp; //same for both cases
            prev = i;
        }
        return Math.max(used, avoid);
    }
}
