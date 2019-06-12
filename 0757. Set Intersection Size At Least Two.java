class Solution {  
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) - > { //start vals are ascending, if start vals are equal, then sort end vals descendingly
            if (a[0] != b[0]) return a[0] - b[0];
            return b[1] - a[1];
        });
        int res = 0, N = intervals.length;
        int[] todo = new int[N];
        Arrays.fill(todo, 2); //two numbers we need to fit into S
        for (int i = N - 1; i != -1; i--) {
            int s = intervals[i][0];
            int td = todo[i];
            res += td;
            for (int v = s; v < s + td; v++) { //either 0,1,or 2 diff values to test
                // System.out.println(td);
                for (int j = 0; j < i; j++) {
                    if (intervals[j][1] >= v && todo[j] != 0) todo[j]--;
                }
            }
        }
        return res;
    }
}
