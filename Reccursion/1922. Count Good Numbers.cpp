 class Solution {
public:
    const int mod = 1e9 + 7; 
long long power(long long x, long long n) {
    // Base case: Any number raised to the power 0 is 1
    if (n == 0)
        return 1;

    // Recursive case: Calculate power using x^(n/2) * x^(n/2)
    long long half = power(x, n / 2);
     half=(half * half)%mod;
    // If n is even, x^n = (x^(n/2)) * (x^(n/2))
    // If n is odd,  x^n = (x^(n/2)) * (x^(n/2)) * x
    if (n % 2 == 0)
        return half;
    else
        return (half * x)%mod;
}

    int countGoodNumbers(long long n) {
       long long e=(n+1)/2;
       long long o=(n/2);
       return (power(5,e)*power(4,o))%mod;
    }
};
