class Solution {
public:
    bool checkOverlap(int rad, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x_diff = (abs(x_center - x1) + abs(x_center - x2) - (x2 - x1))/2;  // distance horizontally from rect
        int y_diff = (abs(y_center - y1) + abs(y_center - y2) - (y2 - y1))/2;
        return x_diff * x_diff + y_diff * y_diff <= rad * rad;  // is distance to rectangle within circle's span?
        
    }
};


