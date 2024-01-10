class Solution {
public:
    vector<vector<int>>directions{
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1}
    };
    vector<vector<int>> imageSmoother(vector<vector<int>>& inputImage) {
       // Save the dimensions of the image.
        int rows = inputImage.size();
        int cols = inputImage[0].size();

        // Create a new image of the same dimension as the input image.
        vector<vector<int>> smoothImage(rows, vector<int>(cols));

        // Iterate over the cells of the image.
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Initialize the sum and count 
                int sum = 0;
                int count = 0;

                // Iterate over all plausible nine indices.
                for(auto it:directions){
                    int x=i+it[0];
                    int y=j+it[1];
                        // If the indices form valid neighbor
                        if (0 <= x && x < rows && 0 <= y && y < cols) {
                            sum += inputImage[x][y];
                            count += 1;
                        }
                    }
                

                // Store the rounded down value in smoothImage[i][j].
                smoothImage[i][j] = sum / count;
            }
        }

        // Return the smooth image.
        return smoothImage; 
    }
};