class Solution {
    public:

        struct Datum {
            double cx, cy;
            long len;
            int x1, y1, x2, y2;
            Datum(double cx, double cy, long len, int x1, int y1, int x2, int y2): cx(cx), cy(cy), len(len), x1(x1), y1(y1), x2(x2), y2(y2) {}
        };

    double minAreaFreeRect(vector < vector < int >> & points) {
        vector < Datum > data;
        int N = points.size();
        for (int i = 0; i != N; i++)
            for (int j = 0; j != i; j++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                long len = (long)(x1 - x2) * (x1 - x2) + (long)(y1 - y2) * (y1 - y2);
                Datum dat((x1 + x2) / 2.0, (y1 + y2) / 2.0, len, x1, y1, x2, y2);
                data.push_back(dat);
            }

        double res = DBL_MAX;
        N = data.size();
        for (int i = 0; i != N; i++) // find another diag with same center and length
            for (int j = 0; j != i; j++) {
                if (compat(data[i], data[j]))
                    res = min(res, area(data[i], data[j]));
            }
        return res == DBL_MAX ? 0 : sqrt(res);
    }

    bool compat(Datum a, Datum b) { // diags have same center and length
        return a.cx == b.cx && a.cy == b.cy && a.len == b.len;
    }

    double area(Datum a, Datum b) { // area of rectangle
        double d1 = dist(a.x1, a.y1, b.x1, b.y1); // side length1
        double d2 = dist(a.x1, a.y1, b.x2, b.y2);
        return d1 * d2;
    }

    double dist(double ax, double ay, double bx, double by) {
        return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    }
};
