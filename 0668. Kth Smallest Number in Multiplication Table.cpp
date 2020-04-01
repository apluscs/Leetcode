class Solution {
public:
    int findKthNumber(int N, int M, int k) {
        int low = 1, high = N * M;
        while(low <= high){
            int mid = int( (long(low) + high) / 2 ), count = count_le(N, M, mid);
            if(count < k)
                low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    
    int count_le(int N, int M, int num){
        int i = 1, j = M, res = 0;
        while(i <= N){
            while(j != 0 && i * j > num) j--;
            res += j;
            i++;
        }
        return res;
    }
};
