import sys
a3 = int(sys.stdin.readline())
a2 = int(sys.stdin.readline())
a1 = int(sys.stdin.readline())
b3 = int(sys.stdin.readline())
b2 = int(sys.stdin.readline())
b1 = int(sys.stdin.readline())
aTotal = 3*a3+2*a2+a1
bTotal = 3*b3+2*b2+b1
if aTotal>bTotal:
  print("A")
elif bTotal>aTotal:
  print("B")
else:
  print("T")
