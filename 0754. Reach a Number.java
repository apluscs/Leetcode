class Solution {
    public int reachNumber(int target) {
        if (target < 0) target *= -1; //get absolute value of target
        int curr = 1, sum = 1;
        while (sum < target) { //if sum can't reach target, then subtracting numbers from it definitely cannot
            curr++;
            sum += curr;
        }
        while ((sum - target) % 2 == 1) { //once you find sum, you know you can get all numbers from subtracting multiples of 2 from it
            curr++;
            sum += curr;
        }
        return curr;
    }
}
