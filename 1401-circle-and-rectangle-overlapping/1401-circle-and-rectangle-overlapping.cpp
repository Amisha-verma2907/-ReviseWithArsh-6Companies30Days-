class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
//         int nearestX = max(x1,min(x2,xCenter));
//         int nearestY = max(y1,min(y1,yCenter));
        
//         int dis_X = nearestX - xCenter;
//         int dis_Y = nearestY - yCenter;
        
//         int m=sqrt(dis_X*dis_X + dis_Y*dis_Y);
//         return m <= radius;
        
        int nearestX = max(x1, min(x2, xCenter));
        int nearestY = max(y1, min(y2, yCenter));

        int distX = xCenter - nearestX;
        int distY = yCenter - nearestY;
        return distX * distX + distY * distY <= radius*radius;
    }
};