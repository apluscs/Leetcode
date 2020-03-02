class NumArray {
public:
    vector<int> tree;
    int N;
    NumArray(vector<int>& nums) {
        N = nums.size();
        tree.resize(N * 2);
        for(int i = N; i != N << 1; ++i)
            tree[i] = nums[i-N];    // fill in leaf nodes, condense towards right side
        for(int i=N-1; i > 0; --i)
            tree[i] = tree[i*2] + tree[i*2+1];  // tree[0] is a dummy
    }
    
    void update(int i, int val) {
        i += N;
        tree[i] = val;
        i /= 2;
        while(i != 0){  // first "invalid" index
            tree[i] = tree[i*2] + tree[i*2+1];
            i /= 2;
        }
    }
    
    int sumRange(int l, int r) {
        // get leaf with value 'l'
        l += N;
        // get leaf with value 'r'
        r += N;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) { // l is bottommost border of desired range, other part needed in desired range will not be included in node l
               sum += tree[l];
               l++; // advances "past" this chunk and onto a whole new range (more in middle)
            }
            if ((r % 2) == 0) { // r is topmost part of desired range, other part is not included by node r
               sum += tree[r];
               r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
