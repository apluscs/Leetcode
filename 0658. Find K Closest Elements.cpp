class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, N = arr.size(), high = N - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid + k < N && x - arr[mid] > arr[mid + k] - x)  // if condition is false
                low = mid + 1;
            else high = mid - 1;
        }
        return vector<int> (arr.begin() + low, arr.begin() + low + k);
    }
    
    // think of sliding window - properties of optimal sliding window are that:
    // dist(first elem to x) is <= dist(first elem NOT in window to x) <-- must
    // be true, or otherwise we would have included that last one and not the current
    // first one. 
    // strategy: bin search for first one that makes this condition true
};
