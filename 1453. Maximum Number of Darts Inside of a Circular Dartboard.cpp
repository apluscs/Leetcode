class Solution {  // 14% time, could be much better with angular sweep
public:
    double r;
    double eps=1e-6;
    int numPoints(vector<vector<int>>& points, int r) {
        int res=1,n=points.size();;
        this->r=r;
        for(int i=0;i!=n;++i){
            for(int j=1+i;j!=n;++j){
                if(dist(points[i][0],points[i][1],points[j][0],points[j][1]) -2*r>eps) continue;  // if points span > diameter ==> cannot be on the edge of a circle
                auto centers=get_centers(points[i],points[j]);
                for(auto c:centers){
                    res=max(res,count(c[0],c[1],points));  
                }
                // cout<<endl;
            }
            
        }
        
        return res;
    }
    
    vector<vector<double>> get_centers(vector<int>& p1, vector<int>& p2){
        double d=dist(p1[0],p1[1],p2[0],p2[1]), a=d/2, h=sqrt(r*r-a*a),dx=p2[0]-p1[0], dy=p2[1]-p1[1];   // d=dist between p1 p2, a=dist from p1 to "middle of kite", h=dist from "middle of kite" to a possible center
        
        double mx=p1[0]+dx/d*a,my=p1[1]+dy/d*a; // middle of kite
        if(d==r*2){
            // cout<<"only one "<<mx<<", "<<my<<endl;
            return {{mx,my}}; // only one intersection point
        }
        double cx1=mx-dy/d*h,cy1=my+dx/d*h, cx2=mx+dy/d*h, cy2=my+dx/d*h;
        // cout<<p1[0]<<", "<<p1[1]<<", "<<p2[0]<<", "<<p2[1]<<endl;
        // cout<<cx1<<", "<<cy1<<", "<<cx2<<", "<<cy2<<endl;
        
        return {{cx1,cy1}, {cx2,cy2}};
    }
    
    double dist(double x1,double y1,double x2,double y2){
        return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    
    int count(double cx,double cy, vector<vector<int>>& points){  // how many points fall under circle with center cx,cy
        int res=0;
        for(auto p:points){
            if(dist(cx,cy,p[0],p[1])- r <= eps)res++;   // eps is needed in case of round off error (ex. dist is 4.00000001 and r=4, this point should pass bc it's probably just floating points messing up)
        }
        // cout<<"center="<<cx<<","<<cy<<", res="<<res<<endl;
        return res;
    }
};
