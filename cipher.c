// Project: 	Caesar Ciphers – cipher.c
// Author:	Yonglei Tao

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char encrypt(char ch, int k);

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []);

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target);

// initialize the encrypt array with appropriate cipher letters according 
// to the given key
void initializeEncyptArray(char key[], char encrypt[]);

// initialize the decrypt array with appropriate substitute letters based 
// on the encrypt array
void initializeDecyptArray(char encypt[], char decrypt[]);

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

int main(int argc, char* argv[])
{  
	int choice, key;
	char ch;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}
	
	choice = atoi(argv[1]);
	key = atoi(argv[2]);

	if (choice == 2)
		key = -key;
	
    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}

	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt(ch, key));
	}

	fclose(fin);
	fclose(fout);

	return 0;
}

/**
	Perform encryption of a character using the Caesar cipher,
	or decryption if parameter k has a negative value.
	@param ch the character to encrypt
	@param k the encryption key
	@return the encrypted character
*/
char encrypt(char ch, int k)
{
	if ( k < 0 )
		k = k + 26;

	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';
	
	return ch;
}


// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []){


}

// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target){


}

// initialize the encrypt array with appropriate cipher letters according 
// to the given key
void initializeEncyptArray(char key[], char encrypt[]){


}

// initialize the decrypt array with appropriate substitute letters based 
// on the encrypt array
void initializeDecyptArray(char encypt[], char decrypt[]){


}

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]){


}

