class Solution {
public:
    int reverse(int x) {
        int count = 0;
        
        while (x != 0) {
            int digit = x % 10;  // Extract the last digit
            x /= 10;  // Remove the last digit from x
            
            // Check for overflow before updating count
            if (count > INT_MAX/10 || (count == INT_MAX/10 && digit > 7)) return 0;
            if (count < INT_MIN/10 || (count == INT_MIN/10 && digit < -8)) return 0;
            
            count = count * 10 + digit;  // Append the digit to the reversed number
        }
        
        return count;
    }
};
