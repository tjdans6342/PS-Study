T = int(input())

for _ in range(T): # T번 반복
	R, S = input().split()
	R = int(R)

	ans = ''
	for u in S:
		ans += u*R

	print(ans)
	