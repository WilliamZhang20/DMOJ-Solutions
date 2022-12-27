n = int(input())
p=0
for i in range(1, 6):
  for j in range(0, 6):
    if i+j==n:
      p+=1
if n%2==0:
  p=(int)((p+2)/2)
else:
  p = (int)((p+1)/2)
print(p)
