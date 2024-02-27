class Solution {
public:
    bool rotateString(string s, string goal) {
     // int m=s.size();
     // int n=goal.size();
     //    bool ans=true;
     //    if(m!=n)
     //    {
     //        ans=false;
     //    }
     //    else{
     //    string temp=s+goal;
     //    if(temp.find(goal))
     //    {
     //        ans= true;
     //    }
     //    else{
     //        ans= false;
     //    }
     //    }
     //    return ans;
        
        int m=s.size();
        int n=goal.size();
        bool ans=false;
        queue<char>q1,q2;
        for(int i=0;i<m;i++)
        {
            q1.push(s[i]);
        }
        
        for(int i=0;i<n;i++)
        {
            q2.push(goal[i]);
        }
        if(q1==q2)
        {
            return true;
        }
        int k=m-1;
        while(k!=0)
        {
            char ch=q2.front();
            q2.pop();
            q2.push(ch);
            if(q1==q2)
            {
               ans = true; 
            }
            k--;
        }
        return ans;
    }
};