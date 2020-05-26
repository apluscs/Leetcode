class Solution {
public:
    int N;
    int kthSmallest(vector<vector<int>>& grid, int k) {
        N = grid.size();
        if(N == 0) return 0;
        int low = grid[0][0], high = grid[N-1][N-1];
        while(low <= high){
            int mid = int((long(low) + high)/2), count = count_smaller(grid, mid);
            if(count < k)
                low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    
    int count_smaller(vector<vector<int>>& grid, int tar){  // returns #elements in grid with value <= tar
        int i = 0, j = N - 1, res = 0;
        while(j != -1 && i != N){   // for each row
            while(j != -1 && grid[i][j] > tar) j--; // find the rightmost element <= tar
            res += j + 1;   // if j == -1, this will be 0
            i++;    // for next row, you can eliminate everything to the right bc of grid's properties
        }
        return res;
    }
};
