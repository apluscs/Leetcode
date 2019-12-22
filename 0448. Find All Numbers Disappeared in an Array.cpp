class Solution {    // 23% runtime , 100% memory
    public:
        vector < int > findDisappearedNumbers(vector < int > & nums) {
            vector < int > res;
            int N = nums.size();
            for (int i = 0; i != N; i++) {
                if (nums[i] == -1 || nums[i] == i + 1) continue;
                int j = nums[i] - 1;
                nums[i] = -1; //set this cell to empty (-1)
                while (j >= 0 && nums[j] != j + 1) { //j is where curr is supposed to be
                    int temp = nums[j]; // save what's there
                    nums[j] = j + 1;
                    j = temp - 1; //where temp is supposed to be
                }
            }
            for (int i = 0; i != N; i++)
                if (nums[i] != i + 1) res.push_back(i + 1);
            return res;
        }
};

class Solution2 {   //slightly slower! same memory
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int N=nums.size();
        for(int i=0;i!=N;i++){
            int pos=abs(nums[i])-1; //because nums[i] might be negative
            nums[pos]= nums[pos] > 0? -nums[pos] : nums[pos];   //mark this index as have been seen
        }
        for(int i=0;i!=N;i++) if(nums[i]>0) res.push_back(i+1);
        return res;
    }
};
