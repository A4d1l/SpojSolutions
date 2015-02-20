

def Sum(a,n):
    return n*(2*a+(n-1)*a)/2

N3=999/3
N5=999/5
N15=999/15

S3=Sum(3,N3)
S5=Sum(5,N5)
S15=Sum(15,N15)

S=S3+S5-S15

print S
