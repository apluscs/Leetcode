class Solution {
    public int maxProfit(int[] prices, int fee) {
        int cash = 0, hold = -prices[0]; //profit if you don't buy on Day 0? buy?
        for (int i = 1; i < prices.length; i++) {
            cash = Math.max(cash, hold + prices[i] - fee); //no change vs. sell at price[i] (& pay fee)
            hold = Math.max(hold, cash - prices[i]); //no change vs. buy at price[i]
            // System.out.println("cash "+cash+", hold "+hold);
        }
        return cash;
    }
}
