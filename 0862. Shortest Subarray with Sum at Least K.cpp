class Solution {
    public:
        int shortestSubarray(vector < int > & A, int K) {
            int N = A.size(), res = N + 1;
            vector < long > sum(N + 1);
            for (int i = 0; i < N; i++) // cumm sum of A, just shifted right 1 index
                sum[i + 1] = (long) A[i] + sum[i];
            deque < int > deq;

            for (int i = 0; i <= N; i++) {
                while (!deq.empty() && sum[i] <= sum[deq.back()])
                    deq.pop_back(); // for all future i, this i is guaranteed to lead to a "better" subarray since it's later 
                    // AND sum[this_i] < sum[back()], so the subarrays formed will surely be of greater value 
                while (!deq.empty() && sum[i] >= sum[deq.front()] + K) { // you have a good valid subarray   
                    res = min(res, i - deq.front());
                    deq.pop_front(); // any other valid subarray starting from front()
                } //will be longer than i-front(), since i will only increase from here
                deq.push_back(i);
            }

            return res == N + 1 ? -1 : res; //still haven't found a heavy enough subarrray? -1
        }
};
