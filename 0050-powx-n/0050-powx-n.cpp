class Solution {
public:
    double myPow(double x, int n) {
        // Convert to long long to prevent integer overflow when making n positive
        long long N = n; 
        
        // Handle negative powers right at the beginning
        if (N < 0) {
            N = -N;
            x = 1.0 / x;
        }
        
        return solve(x, N);
    }
    
private:
    double solve(double x, long long n) {
        // Base cases
        if (n == 0) return 1.0;
        if (n == 1) return x;
        
        // Recursive steps
        if (n % 2 == 0) {
            return solve(x * x, n / 2);
        } else {
            return x * solve(x * x, n / 2);
        }
    }
};