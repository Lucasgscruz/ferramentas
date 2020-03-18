# Diamonts and Sand

def main():
	N = int(raw_input())

	while(N):
		cont = 0;
		mine = ""
		diamonts = []
		
		mine = raw_input()

		for i in mine:
			if(i == '<'):
				diamonts.append(i)
		
			elif(i == '>'):
				if(diamonts):
					diamonts.pop();
					cont += 1;	

		print cont
		N = N - 1

if __name__ == '__main__':
	main()
