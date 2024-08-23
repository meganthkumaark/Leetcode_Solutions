class Solution {
public:
    int mod=1e9+7;
    long long factorial(int n) {
        return (n==1 || n==0) ? 1: ((n%mod)*factorial(n - 1))%mod;  
    } 
    bool isPrime(int n){
        if (n <= 1)
            return false;
        for (int i = 2; i <= n / 2; i++){
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int numPrimeArrangements(int n) {
        int noOfPrime=0;
        for(int i=1;i<=n;i++){
            if(isPrime(i)){
                noOfPrime++;
            }
        }
        int nonPrime=n-noOfPrime;
        cout<<noOfPrime<<" "<<nonPrime<<endl;
        return (factorial(noOfPrime)*factorial(nonPrime))%mod;
    }
};