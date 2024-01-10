class Solution {
public:
    vector<vector<int>>directions{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
       // Save the dimensions of the image.
//         int rows = inputImage.size();
//         int cols = inputImage[0].size();

//         // Create a new image of the same dimension as the input image.
//         vector<vector<int>> smoothImage(rows, vector<int>(cols));

//         // Iterate over the cells of the image.
//         for (int i = 0; i < rows; i++) {
//             for (int j = 0; j < cols; j++) {
//                 // Initialize the sum and count 
//                 int sum = 0;
//                 int count = 0;

//                 // Iterate over all plausible nine indices.
//                 for(auto it:directions){
//                     int x=i+it[0];
//                     int y=j+it[1];
//                         // If the indices form valid neighbor
//                         if (0 <= x && x < rows && 0 <= y && y < cols) {
//                             sum += inputImage[x][y];
//                             count += 1;
//                         }
//                     }
                

//                 // Store the rounded down value in smoothImage[i][j].
//                 smoothImage[i][j] = sum / count;
//             }
//         }

//         // Return the smooth image.
//         return smoothImage; 
        int m=img.size();
        int n=img[0].size();
        
        vector<int>prevRow(n);
        int prevCorner = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=0;
                int count=0;
                //bottom neighbours
                if(i+1<m)
                {
                    if(j-1>=0)
                    {
                        sum+=img[i+1][j-1];
                        count++;
                    }
                    sum+=img[i+1][j];
                    count++;
                    if(j+1<n)
                    {
                        sum+=img[i+1][j+1];
                        count++;
                    }
                }
                //just after neighbour
                if(j+1<n)
                {
                    sum+=img[i][j+1];
                    count++;
                }
                //just left neighbour
                if(j-1>=0)
                {
                    sum+=prevRow[j-1];
                    count++;
                }
                //current cell
                sum+=img[i][j];
                count++;
                
                //top corner neighbours
                if(i-1>=0)
                {
                    if(j-1>=0)
                    {
                        sum+=prevCorner;
                        count++;
                    }
                    sum+=prevRow[j];
                    count++;
                    if(j+1<n)
                    {
                        sum+=prevRow[j+1];
                        count++;
                    }
                }
                //store prev value of prevRow
                if(i-1>=0)
                {
                    prevCorner=prevRow[j];
                }
                
                //store current value of [i][j]
                prevRow[j]=img[i][j];
                
                img[i][j]=sum/count;
            }
        }
        return img;
    }
};