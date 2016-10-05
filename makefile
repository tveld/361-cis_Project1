cipher: cipher.c
	gcc cipher.c -o cipher

test: test1
test1:
	./cipher 1 Testing A_Tale_of_Two_Cities.txt encrypt
	./cipher 2 Testing encrypt decrypt
	diff -s decrypt A_Tale_of_Two_Cities.txt
