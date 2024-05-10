class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
//        int n = word.length();
        
//         unordered_map<string,int>mp;
        
//         for(int i=0;i<n;i+=k){
//             string ss = word.substr(i,k);
//             mp[ss]++;
//         }
//         int mf=0;
//         for(const auto & p:mp){
//             mf=max(mf,p.second);
            
//         }
//         return (n/k) - mf;
    // Check if the string is already k-periodic
//     std::string pattern = word.substr(0, k);
//     bool isKPeriodic = true;
//     for (int i = k; i < n; i += k) {
//         if (word.substr(i, k) != pattern) {
//             isKPeriodic = false;
//             break;
//         }
//     }
//     if (isKPeriodic) return 0;
    
//     // Count frequency of substrings of length k
//     std::unordered_map<std::string, int> frequency;
//     for (int i = 0; i < n - k + 1; i++) {
//         frequency[word.substr(i, k)]++;
//     }
    
//     // Find the most frequent substring
//     int maxFreq = 0;
//     for (const auto& pair : frequency) {
//         maxFreq = std::max(maxFreq, pair.second);
//     }
    
//     // Calculate minimum number of operations
//     return n - maxFreq; 
        
        unordered_map<string,int>mp;
        
        int mx=0;
        
        for(int i=0;i<word.size();i+=k)
        {
            string portion = word.substr(i,k);
            mp[portion]++;
            
            mx=max(mx,mp[portion]);
        }
        return ((word.size()/k) - mx);
    }
};