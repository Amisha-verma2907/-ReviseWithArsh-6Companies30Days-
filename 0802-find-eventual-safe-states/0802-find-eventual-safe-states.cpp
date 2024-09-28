class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        
        vector<vector<int>> adjRev(V);  // Reversed graph adjacency list
        vector<int> indegree(V, 0);     // In-degree of each node
        
        // Reverse the edges of the graph
        for (int i = 0; i < V; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);  // Reverse the direction of the edge
                indegree[i]++;            // Increase the in-degree of the node
            }
        }
        
        // Queue to process nodes with 0 in-degree
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);  // Safe node
            }
        }
        
        // Vector to store safe nodes
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            safeNodes.push_back(node);
            for (auto neighbor : adjRev[node]) {
                indegree[neighbor]--;
                
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Sort the result as per the problem statement
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
