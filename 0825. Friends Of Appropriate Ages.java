class Solution {
    public int numFriendRequests(int[] nums) {
        int N = nums.length, res = 0;
        int[] frq = new int[121], sum = new int[121];
        for (int n: nums) frq[n]++;
        for (int i = 1; i != 121; i++) sum[i] = frq[i] + sum[i - 1];

        for (int i = 120; i != 0; i--) {
            if (frq[i] == 0) continue; //only processes ages people have
            int start = i / 2 + 7;
            if (start >= i) break; //you are too young, minimum age is above you! everyone younger than you is the same way
            while (start != 0 && frq[start] == 0) start--; //find first age too young to request
            // System.out.println("Start: "+start+", "+frq[start]);
            int oneP = sum[i] - sum[start] - 1; //#requests of one person this age (minus themself); 
            //sum stuff is #people between start and you(inclusive of upper bound)
            res += oneP * frq[i]; //multiply by #people that age
            // System.out.println(oneP+", "+res);
        }
        return res;
    }
}
