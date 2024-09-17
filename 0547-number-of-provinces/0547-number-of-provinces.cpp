class Solution {
private:
    // DFS function to explore all connected cities
    void dfs(int city, vector<int>& vis, vector<int> adjLs[]) {
        vis[city] = 1;  // Mark the current city as visited
        
        // Visit all the adjacent cities
        for(auto it : adjLs[city]) {
            if(!vis[it]) {
                dfs(it, vis, adjLs);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjLs[n];  // Create adjacency list
        
        // Build the adjacency list from the isConnected matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n, 0);  // Initialize the visited array
        int provinces = 0;  // To count the number of provinces
        
        // Loop through each city and perform DFS if it's not visited
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                provinces++;  // New province found
                dfs(i, vis, adjLs);  // Explore all cities in this province
            }
        }
        
        return provinces;  // Return the number of provinces
    }
};
