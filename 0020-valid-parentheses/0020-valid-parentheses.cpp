class Solution {
public:
    bool isValid(string s) {
//         stack<char>m;
        
        
//         for(int i=0;i<s.size();i++)
//         {
//            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
//                m.push(s[i]);
//            }
//             else{
//                 char l= s[i];
//                 char k = m.top();
//                 m.pop();
//                 if((l == ')' && k == '(')|| (l == '}' && k == '{') || (l == ']' && k == '[')){
                    
//                    continue;
//                 }else{
//                     return false;
//                 }
//             }
//         }
//        if(m.empty()){
//            return true;
//        }
//         return false;
        
        
         stack<char>st; 
        for(auto it: s) {
            if(it=='(' || it=='{' || it == '[') st.push(it); 
            else {
                if(st.size() == 0) return false; 
                char ch = st.top(); 
                st.pop(); 
                if((it == ')' and ch == '(') or  (it == ']' and ch == '[') or (it == '}' and ch == '{')) continue;
                else return false;
            }
        }
        return st.empty(); 
    }
};