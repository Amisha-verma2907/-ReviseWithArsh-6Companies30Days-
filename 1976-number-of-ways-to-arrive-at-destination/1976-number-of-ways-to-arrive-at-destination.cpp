class Solution {
    int mod = (int) 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Creating adjacency list to represent the graph
        vector<pair<int, int>> adj[n];
        for (auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // To store the number of ways to reach each node
        vector<long long> ways(n, 0);
        // To store the shortest distance to each node
        vector<long long> dist(n, LLONG_MAX); // Use long long to handle large distances
        
        // Start from node 0
        dist[0] = 0;
        ways[0] = 1;
        
        // Priority queue to pick the minimum distance node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0}); // {distance, node}
        
        while (!pq.empty()) {
            auto top = pq.top();
            long long dis = top.first;
            int node = top.second;
            pq.pop();
            
            // Skip processing if the current distance is greater than the recorded shortest distance
            if (dis > dist[node]) continue;
            
            for (auto& it : adj[node]) {
                int neighbor = it.first;
                long long d = it.second;
                
                // Relaxation step
                if (dis + d < dist[neighbor]) {
                    dist[neighbor] = dis + d;
                    ways[neighbor] = ways[node]; // Inherit the ways from the current node
                    pq.push({dis + d, neighbor});
                } else if (dis + d == dist[neighbor]) {
                    // If it's another shortest path, add the number of ways
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n - 1] % mod; // Return the number of ways to reach the last node
    }
};
