N = int(raw_input())

while(N):
	X = int(raw_input())
	X = 2**X;
	X = X/12/1000
	print X, "kg"
	N = N-1;
