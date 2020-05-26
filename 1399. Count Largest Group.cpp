class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> frq; // sum to #in the group
        for(int i = 1; i <= n; ++i){
            int sum = sum_digits(i);
            frq[sum]++;
        }
        unordered_map<int,int> group_sizes;
        for(auto p : frq){
            group_sizes[p.second]++;    // p.second is group size
        }
        int res = 0;
        for(auto p : group_sizes){
            if(res < p.first)
                res = p.first;
        }
        return group_sizes[res];
    }
    
    int sum_digits(int num){
        int res = 0;
        while(num != 0){
            res += num % 10;
            num /= 10;
        }
        return res;
    }
};
