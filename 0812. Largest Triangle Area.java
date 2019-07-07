class Solution {
    public double largestTriangleArea(int[][] points) {
        int N = points.length;
        double res = 0;
        for (int i = 0; i != N; i++)
            for (int j = i + 1; j != N; j++)
                for (int k = j + 1; k != N; k++) {
                    double a = area(points[i], points[j], points[k]);
                    res = Math.max(res, a);
                    // System.out.print((int)res+" ");
                    // if(k%10==0) System.out.println();
                }
        // System.out.println(res);
        return res;
    }

    double area(int[] p1, int[] p2, int[] p3) { //herons formula
        double ax = p1[0] - p2[0], ay = p1[1] - p2[1], bx = p2[0] - p3[0], by = p2[1] - p3[1], cx = p1[0] - p3[0], cy = p1[1] - p3[1]; //horz and vert distances between points
        double a = Math.sqrt(ax * ax + ay * ay), b = Math.sqrt(bx * bx + by * by), c = Math.sqrt(cx * cx + cy * cy);
        double s = (a + b + c) / 2;
        double res = s * (s - a) * (s - b) * (s - c);
        return res < 0 ? 0 : Math.sqrt(res); //if collinear, res might be neg
    }
}
