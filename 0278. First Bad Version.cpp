// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int N) {
        int low = 1, high = N;
        while(low <= high){
            int mid = int((long(low) + high) / 2);
            bool b = isBadVersion(mid);
            if(!b)
                low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
