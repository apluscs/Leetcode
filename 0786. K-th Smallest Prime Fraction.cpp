class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int K) {
        int N = nums.size();
        vector<int> res(3);
        double low = double(nums[0])/nums[N-1], high = 1;   // low is smallest int / largest int
        while(low < high){
            double mid = (low + high) / 2;
            res = count_le(nums, N, mid);
            if(res[0] < K)
                low = mid;
            else if(res[0] == K)    // somehow always guranteed to work
                break;
            else high = mid;
        }
        return {res[1], res[2]};
    }
    
    vector<int> count_le(vector<int>& nums, int N, double m){ // first num in res is count, second are numer and denom of fraction <= num
        int i = 0, j = 1;
        vector<int> res = {0,10,1}; // 10 - 1 is larger than any possible fraction [0,1]
        while(i <= N){
            while(j != N && m * nums[j] < nums[i]) j++; // pass through all fractions > m
            res[0] += N - j;    // 
            if(j == N) break;   
            double curr_diff = abs(double(res[1])/res[2] - m);  // how far current res is from m 
            if(res.size() == 0 || abs(double(nums[i])/nums[j] - m) < curr_diff){    // if this is closer to m than curr_diff is
                res.resize(3);
                res[1] = nums[i];
                res[2] = nums[j];
            }
            i++;
        }
        return res;
    }
};
    
    
