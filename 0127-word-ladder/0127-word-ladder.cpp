class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        
        q.push({beginWord,1});
        
        set<string>s(wordList.begin(),wordList.end());
        
        s.erase(beginWord);
        
        while(!q.empty()){
            string str = q.front().first;
            int step = q.front().second;
            
            q.pop();
            if(str == endWord)return step;
            for(int i=0;i<str.size();i++){
                char original = str[i];
            for(char ch = 'a';ch<='z';ch++)
            {
                str[i] = ch;
                
                if(s.find(str) != s.end()){
                    s.erase(str);
                    q.push({str,step+1});
                }
            }
            str[i] = original;
           }
        }
        
        return 0;
    }
};