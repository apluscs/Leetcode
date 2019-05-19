class Solution {
    public int[] dailyTemperatures(int[] nums) {
        int[] res = new int[nums.length];
        Stack < Integer > st = new Stack < > (); //store indices of elements
        for (int i = nums.length - 1; i != -1; i--) {
            while (!st.empty() && nums[st.peek()] <= nums[i]) st.pop();
            if (!st.empty()) res[i] = st.peek() - i;
            st.push(i); //Intuition: higher days that come earlier kick out lower days that come later
        } //but save higher days that come later for high-ish days earlier in the schedule
        return res;
    }
}

class SolutionFast {    //int[] to represent stack, much faster
    public int[] dailyTemperatures(int[] nums) {
        int[] st = new int[nums.length];
        int[] res = new int[nums.length];
        int top = -1;
        for (int i = nums.length - 1; i != -1; i--) {
            while (top != -1 && nums[st[top]] <= nums[i]) {
                top--;
            }
            if (top != -1) res[i] = st[top] - i;
            st[++top] = i;
        }
        return res;
    }
}
