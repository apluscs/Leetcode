class Solution {
    public String reorganizeString(String str) {
        int N = str.length();
        int[][] frq = new int[26][2]; //(frequnecy, char's int val)
        for (int i = 0; i != N; i++) frq[str.charAt(i) - 'a'][0]++;
        for (int i = 0; i != 26; i++) frq[i][1] = i + 'a'; //char int val
        Arrays.sort(frq, (a, b) - > b[0] - a[0]); //descendingly, most frequent are dealt with first

        if (frq[0][0] > (N + 1) / 2) return ""; //if the most frequent can fit, everyone can too; if it can't, we can't reorganize
        int ind = -1, count = 0;
        char c = ' '; //bogus
        char[] res = new char[N];
        for (int i = 0; i < N; i += 2) { //even indices
            if (count == 0) { //fill in all instances of this char we need to
                ind++; //new char to fill in
                c = (char) frq[ind][1];
                count = frq[ind][0];
            }
            res[i] = c;
            count--;
        }
        for (int i = 1; i < N; i += 2) { //odd indices
            if (count == 0) {
                ind++;
                c = (char) frq[ind][1];
                count = frq[ind][0];
            }
            res[i] = c;
            count--;
        }
        return new String(res);
    }
}

class SolutionOther {   //same speed, same memory
    public String reorganizeString(String str) {
        int N = str.length();
        int[][] frq = new int[26][2]; //(frequnecy, char's int val)
        for (int i = 0; i != N; i++) frq[str.charAt(i) - 'a'][0]++;
        for (int i = 0; i != 26; i++) frq[i][1] = i + 'a'; //char int val
        PriorityQueue < int[] > pq = new PriorityQueue < > ((a, b) - > b[0] - a[0]); //descendingly, most frequent are dealt with first
        for (int[] f: frq) pq.add(f);

        int[] max = pq.peek();
        if (max[0] > (N + 1) / 2) return "";
        char[] res = new char[N];
        for (int i = 0; i < N - 1; i += 2) { //leaves one hanging out if N is odd
            int[] arr1 = pq.poll();
            int[] arr2 = pq.poll(); //top two frequencies
            res[i] = (char) arr1[1];
            res[i + 1] = (char) arr2[1];
            arr1[0]--;
            arr2[0]--;
            pq.add(arr1);
            pq.add(arr2);
        }
        if (N % 2 == 1) res[N - 1] = (char) pq.poll()[1]; //last one doesn't have a pair
        return new String(res);
    }
}
