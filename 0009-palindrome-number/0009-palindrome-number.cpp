class Solution {
public:
    bool isPalindrome(int x) {
     if(x<0){
            return false;
        }
        int num = x;
        long sum = 0;
        while(num != 0){
            int a = num%10;
            num /= 10;
            sum = (sum*10)+a;
        }
        if(sum == x){
            return true;
        }
        return false;
    
    }
};