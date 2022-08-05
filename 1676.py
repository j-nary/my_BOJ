def factorial(n) :
    if n == 1 or n == 0 : return 1
    else : return n * factorial(n-1)

N = int(input())
res = str(factorial(N))[::-1]
cnt = 0;
for i in range(len(res)) :
    if res[i] == '0' : cnt += 1
    else : break

print(cnt)
