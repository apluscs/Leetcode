class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec2[0] < rec1[2] && rec2[2] > rec1[0] && rec2[1] < rec1[3] && rec2[3] > rec1[1];
    } //rec2 bot must be below rec1 top, rec2 top must be above rec1 bottom
    //rec2 left must be left of rec1 right, rec2 right must be right of rec1 left
}
