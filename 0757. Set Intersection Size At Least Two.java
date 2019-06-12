class SolutionFast {
    public int intersectionSizeTwo(int[][] intervals) {
        Arrays.sort(intervals, (a, b) - > { //ascending end vals
            return a[1] - b[1];
        });
        int res = 0, N = intervals.length, max = -1, max2 = -1; //max's are largest 2 nums we previously added to S
        for (int i = 0; i != N; i++) {
            int s = intervals[i][0], e = intervals[i][1];
            if (s > max) {
                res += 2;   //need to add 2 new nums into S
                max = e;
                max2 = e - 1;
            } else if (s > max2) {  //keep one and add 1 new num into S, update max's accordingly
                res++;
                max2 = max;
                max = e;
            }   //max's fit into this interval, no need to add anything new
        }
        return res;
    }
}

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
