class Solution {
  public:
    double angleClock(int hour, int minutes) {
      double angle1 = ((hour % 12) + minutes / 60.0) * 30; // find how many many "sectors" hour hand is (sector = 1/12 of the circle)
      double angle2 = minutes * 6.0; // each minute is 6 degrees
      double res = abs(angle1 - angle2);
      return res > 180 ? 360 - res : res;
    }
};
