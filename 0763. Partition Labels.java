class Solution {
    public List < Integer > partitionLabels(String str) {
        int[] ends = new int[26];
        int N = str.length();
        for (int i = 0; i != N; i++) ends[str.charAt(i) - 'a'] = i;
        int start = 0, end = ends[str.charAt(0) - 'a'], ind = 0;
        List < Integer > res = new ArrayList < > ();
        while (ind != N) {
            while (ind != end) {
                end = Math.max(end, ends[str.charAt(ind) - 'a']); //bump the end of current interval as far as it needs to go to maintain intervals of all letters within
                ind++;
            }
            res.add(end - start + 1); //only happens when all letters inside this interval have ends also within the interval
            ind++;
            start = ind; //start up new interval
            if (ind != N) end = ends[str.charAt(ind) - 'a'];
            // System.out.println(ind);
        }
        return res;
    }
}

/*
Runtime: 2 ms, faster than 99.67% of Java online submissions for Partition Labels.
Memory Usage: 36 MB, less than 97.93% of Java online submissions for Partition Labels.
*/
