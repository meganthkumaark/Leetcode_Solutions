class Solution:
    def countPrimes(self, n: int) -> int:
        if n<=2:
            return 0
        a = [True]*(n)
        x=2
        while (x*x)<n:
            if a[x]:
                for i in range (x*x,n,x):
                    a[i] = False
            x+=1
        return a.count(True)-2