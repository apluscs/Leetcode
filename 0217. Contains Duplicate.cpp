class Solution {
  public:
    bool containsDuplicate(vector < int > & nums) {
      unordered_set < int > vis;
      for (int num: nums) {
        if (vis.count(num) != 0) return true; //already saw this before
        vis.insert(num);
      }
      return false;
    }
};
