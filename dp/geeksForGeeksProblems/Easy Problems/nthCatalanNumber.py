import sys 
sys.stdin = open('input.txt', 'r')  
sys.stdout = open('output.txt', 'w') 
dp=[0 for i in range(101)]
def initialiseDP():
    dp[0]=1
    for i in range(1,101):
        for j in range(i):
            dp[i]+=(dp[j]*dp[i-j-1])
    # print(dp)
def solve(n):
    return dp[n]
t=int(input())
initialiseDP()
while t:
    n=int(input())
    print(solve(n))
    t-=1