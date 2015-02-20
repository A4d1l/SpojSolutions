A,B=raw_input().split()
MAX_A=A.replace("5","6")
MIN_A=A.replace("6","5")
MAX_B=B.replace("5","6")
MIN_B=B.replace("6","5")

MAX_SUM=int(MAX_A)+int(MAX_B)
MIN_SUM=int(MIN_A)+int(MIN_B)

print MIN_SUM,MAX_SUM
