T=int(raw_input())
for i in range(T):
    N=int(raw_input())
    K=int(5)
    Ans=0
    while N/K>0:
        Ans+=N/K
        K*=5
    print Ans
