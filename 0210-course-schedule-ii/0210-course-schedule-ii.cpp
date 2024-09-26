class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        
        int row = prerequisites.size();
        
        for(int i=0;i<row;i++)
        {
                int first = prerequisites[i][0];
                int second = prerequisites[i][1];
             adj[second].push_back(first);
        }
        
        
        vector<int>indegree(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        
        
        queue<int>q;
        
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        vector<int>order;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            order.push_back(top);
           
            for(auto it:adj[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        if(order.size() == numCourses){
            return order;
        }
        
        return {}; 
    }
};