

class Solution {
  public:
  
  
    bool isBetween(int p[], int r[], int q[]) {
        // if p,q,r is collinear then checking whether r lies on segment p->q
        
        if(r[0] <= max(p[0], q[0]) and r[0] >= min(p[0], q[0]) and r[1] <= max(p[1], q[1]) and r[1] >= min(p[1], q[1])) {
            return true;
        }
        return false;
         
    }
  
    int orientation(int p[], int q[], int r[]) {
        
        // checking p -> q -> r is clockwise, anticlockwise, collinear
        
        // slope of line :: 1 -> 2 :: (y2 - y1)/(x2 - x1)
        
        // if slope of q->r > slope of p->q then orientation is clockwise
        //if slope of q->r < slope of p->q then orientation is anti-clockwise
        //if slope of q->r = slope of p->q then orientation is collinear
        
        
        // (yr - yq)/(xr - xq) compare with (yq - yp)/(xq - xp)
        // is equivalent to comparing :: (yr - yq)*(xq - xp) compare with (yq - yp)*(xr - xq)
        
        
        long long val = (r[1] - q[1])*(q[0] - p[0]) - (q[1] - p[1])*(r[0] - q[0]);
        
        if(val > 0ll) {
            return 1; // clockwise
        }
        if(val < 0ll) {
            return 2; // anticlockwise
        }
        return 0ll; // collinear
        
        
        
    }
  
  
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        // code here
        
        int o1 = orientation(p1,q1,p2);
        int o2 = orientation(p1,q1,q2);
        int o3 = orientation(p2,q2,p1);
        int o4 = orientation(p2,q2,q1);
        
        if(o1 != o2 and o3 != o4) {
            // then definitely intersect
            return "true";
        }
        
        if(o1 == 0 and isBetween(p1, p2, q1) == true) {
            return "true";
        }
        
        if(o2 == 0 and isBetween(p1, q2, q1) == true) {
            return "true";
        }
        
        if(o3 == 0 and isBetween(p2, p1, q2) == true) {
            return "true";
        }
        
        if(o4 == 0 and isBetween(p2, q1, q2) == true) {
            return "true";
        }
    
        return "false";
        
    }
};
