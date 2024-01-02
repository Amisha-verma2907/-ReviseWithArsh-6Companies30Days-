class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=nums[0].size();
        vector<int>res;
        for(auto query:queries){
            int k=query[0];//to find kth smallest value
            int x=query[1];//to trim upto to given x value from right side as mentioned in question
            priority_queue<pair<string,int>>pq;
            for(int i=0;i<n;i++)
            {
                string str=nums[i].substr(m-x);//substring starting value is starting value and last value is where to end id=f not mentioned then it reaches to end
                pq.push({str,i});
                if(pq.size()>k){
                    pq.pop();
                }
                

            }
            res.push_back(pq.top().second);

        }
        return res;
    }
};