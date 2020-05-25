import sys 
sys.stdin = open('input.txt', 'r')  
sys.stdout = open('output.txt', 'w') 
t=int(input())

def printDP(dp):
    for item in dp:
        for ele in item:
            if ele==1111111111111111111111111:
                print('INF',end=' ')
            else:
                print(ele,end=" ")
        print()

def solve(arr,n):
    dp=arr
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if(dp[i][j]>dp[i][k]+dp[k][j]):
                    dp[i][j]=dp[i][k]+dp[k][j]
    return dp

while t:
    n=int(input())
    arr=[]
    for i in  range(n):
        temp=[]
        for j in input().split(' '):
            temp.append(j)
        arr.append(temp)
    i,j=0,0
    while(i<n):
        j=0
        while(j<n):
            # print(i,j)
            if(arr[i][j]=='INF'):
                arr[i][j]=1111111111111111111111111
            else:
                arr[i][j]=int(arr[i][j])
            j+=1
        i+=1
    
    printDP(solve(arr,n))
    t-=1