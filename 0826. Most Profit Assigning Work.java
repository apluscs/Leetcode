class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        int N = difficulty.length;
        int[][] jobs = new int[N][2];
        for (int i = 0; i != N; i++) {
            jobs[i][0] = difficulty[i];
            jobs[i][1] = profit[i];
        }
        Arrays.sort(jobs, (a, b) - > a[0] - b[0]); //sort by difficulty
        int[] maxProf = new int[100001]; //maxProf[i]=max profit if you can handle difficulty i
        int max = 0, j = 0, res = 0;
        for (int i = 0; i != 100001; i++) {
            while (j != N && i >= jobs[j][0]) { //will repeat if there are duplicate jobs of same difficulty
                max = Math.max(max, jobs[j][1]);
                j++;
            }
            maxProf[i] = max;
        }
        Arrays.sort(worker);
        // System.out.println(Arrays.toString(worker));
        // System.out.println(Arrays.toString(maxProf));
        for (int w: worker) {
            res += maxProf[w];
            // System.out.println(maxProf[w]);
        }
        return res;
    }
}
