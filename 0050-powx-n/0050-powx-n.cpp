class Solution {
public:
    double Pow(double x, long long n) {
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            return 1 / Pow(x, -n);
        }
        if (n % 2 == 0) {
            double half = Pow(x, n / 2);
            return half * half;
        } else {
            return x * Pow(x, n - 1);
        }
    }
    
    double myPow(double x, int n) {
       return Pow(x, static_cast<long long>(n));
        
    }
};



// double ans =1.0;
       //  long long nn=n;
       //  if(nn<0) nn = -1 *nn;
       //  while(nn){
       //      if(nn%2 == 0){
       //          x= x*x;
       //          nn= nn/2;
       //      }else{
       //          ans = ans*x;
       //          nn=nn-1;
       //      }
       //  }
       //  if(n < 0) ans = double(1.0) / double(ans);
       //  return ans;