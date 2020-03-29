class Solution {  // definitely wrong
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, N = nums.size(), j = 0;    // j is a pointer in nums
        vector<int> starts(1004);
        for(int i = 0; i != 1001; ++i){
            starts[i] = j;
            while(j < N-1 && nums[j] == i && nums[j+1] == i)
                j++;
            if(j != N && nums[j] == i)
                j++;

        }
        for(int i = 0; i != 6; ++i)
            cout << starts[i] << " ";
        cout << endl;
        for(int i = 0; i != N; ++i){
            for(j = i + 1; j < N; ++j){ // nums[j] > nums[i]
                int low = nums[j] - nums[i] + 1, high = nums[j] + nums[i] - 1;
                res += starts[high + 1] - starts[low];
                if(nums[j] >= low && nums[j] <= high) res--;
                if(nums[i] >= low && nums[i] <= high) res--; 
                cout << nums[i] << ", " << nums[j] << ", " << res << ", " << low << ", " << high << endl;
                while(j < N-1 && nums[j+1] == nums[j]) j++;
            }
            while(i < N-1 && nums[i+1] == nums[i]) i++;
        }
        return res / 2;
    }
    
};
