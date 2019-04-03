class KthLargest {
    public static int K;
    public static PriorityQueue < Integer > pq; //does all sorting for us
    public KthLargest(int k, int[] nums) {
        K = k;
        pq = new PriorityQueue < > ();
        for (int n: nums) add(n); //my method, not PQ's
    }

    public int add(int val) {
        if (pq.size() < K) pq.add(val);
        else if (pq.peek() < val) { //pq is perfect size
            pq.poll();
            pq.add(val);
        }
        return pq.peek(); //least element @ top
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
