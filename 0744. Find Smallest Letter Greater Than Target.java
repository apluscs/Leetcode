class Solution {
    public char nextGreatestLetter(char[] arr, char target) {
        int N = arr.length;
        int low = 0, high = N - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= target) low = mid + 1;
            else high = mid - 1;
        } //high < low now
        if (high != -1 && arr[high] > target) return arr[high];
        if (low != N && arr[low] > target) return arr[low];
        return arr[0];
    }
}

/*
Just a little flex: 

Runtime: 0 ms, faster than 100.00% of Java online submissions for Find Smallest Letter Greater Than Target.
Memory Usage: 37.8 MB, less than 100.00% of Java online submissions for Find Smallest Letter Greater Than Target.
*/
