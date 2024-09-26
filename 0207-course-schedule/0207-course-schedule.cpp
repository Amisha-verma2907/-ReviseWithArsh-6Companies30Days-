class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];  // adjacency list
        
        // Build the graph
        for(int i = 0; i < prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[prereq].push_back(course);  // prereq -> course
        }
        
        // Indegree array to count prerequisites for each course
        vector<int> indegree(numCourses, 0);
        
        // Calculate indegrees
        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        // Queue to perform BFS (courses with no prerequisites)
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        int count = 0;  // Number of courses that can be completed
        
        // BFS
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            
            // Reduce indegree for all dependent courses
            for(auto it : adj[curr]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // If count equals numCourses, all courses can be finished
        return count == numCourses;
    }
};
