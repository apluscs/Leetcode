class Solution {

    public int[] asteroidCollision(int[] nums) {
        Stack < Integer > st = new Stack < > ();
        for (int i = 0; i != nums.length; i++) {
            boolean flag = true;
            while (!st.empty() && nums[i] < 0 && st.peek() > 0) { //collision happens
                if (-nums[i] > st.peek()) {
                    st.pop();
                    continue;
                } else if (-nums[i] == st.peek()) st.pop();
                flag = false;
                break; //flag= do you add nums[i] to stack or does it explode?
            }
            if (flag) st.push(nums[i]);
        }
        int[] res = new int[st.size()];
        for (int i = res.length - 1; i != -1; i--) {
            res[i] = st.pop();
        }
        return res;
    }

}
