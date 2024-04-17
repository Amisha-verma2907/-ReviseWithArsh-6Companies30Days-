class Solution {
public:
    bool isPowerOfTwo(int n) {
        ios_base::sync_with_stdio(false), cin.tie(nullptr);
        int ami = 0;
        if(n < 0) return false;
        for(int i = 0; i < 32; i++){
            ami += ((n >> i) & 1);
        }
        return (ami == 1);
    }
};