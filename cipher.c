// Project: 	Caesar Ciphers – cipher.c
// Author:	Troy Veldhuizen

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sort word array
void sortWord(char word[]);

char encrypt(char ch, int k);

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []);

// search the initial num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target);

// initialize the encrypt array with appropriate cipher letters according 
// to the given key
void initEncryptDecryptArrays(char key[], char encrypt[], char decrypt[]);


// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

int main(int argc, char* argv[])
{  
	int choice, i, len;
	char ch, encryptArray[26], decryptArray[26];
	char *key;
	FILE *fin, *fout;

	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}
	
	choice = atoi(argv[1]);
	key = argv[2];

	removeDuplicates(key);
	
	initEncryptDecryptArrays(key, encryptArray, decryptArray);
	
	for(i = 0; i < 26; ++i){
		printf("%c: %c\n", i + 65, encryptArray[i]);
	}

	printf("\n\nDecrypt Array\n\n");

	for(i = 0; i < 26; ++i){
		printf("%c: %c\n", i + 65, decryptArray[i]);
	}
	

	/*	

	if (choice == 2)
		for(i = 0; i < len; ++i){
		//	key[i] = - key[i];
		}

	
    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}
	
	i = 1;
	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt(ch, key[i % len]));
		++i;	
	}

	fclose(fin);
	fclose(fout);
	*/
	return 0;
}

void sortWord(char word[]){

	int size = strlen(word);
	
	int i, j, temp;
	for (i=0; i<size-1; i++)		// bubble sort data in the array
		for (j=size-1; j>i; j--)
			if (word[j-1] > word[j])
			{
				temp = word[j-1];
				word[j-1] = word[j];
				word[j] = temp;
			}
}

// remove duplicate characters in array word and return the result string
char * removeDuplicates(char word []){
	int i, cnt, len;
	char prev = '\0';
	
	sortWord(word);
	len = strlen(word);

	char solution[strlen(word)];
	
	cnt = 0;
	for(i = 0; i < strlen(word); ++i){

		if(prev != word[i]){
			solution[cnt] = word[i];
			prev = word[i];
			++cnt;
		}
	}
	
	strcpy(word, solution);

	return word;

}


// search the initial num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target){
	

}

// initialize the encrypt array with appropriate cipher letters according 
// to the given key
void initEncryptDecryptArrays(char key[], char encrypt[], char decrypt[]){
	int i, cnt, keylen;

	keylen = strlen(key);
	
	// initially fill arrays with zeros
	for(i = 0; i < 26; ++i){
		encrypt[i] = 0;
		decrypt[i] = 0;
	}
	
	// fill encrypt and decrypt arrays with key
	for(i = 0; i < keylen; ++i){
		encrypt[i] = key[i];
		decrypt[ key[i] - 65] = i + 65;
	}

	cnt = 0;
	
	// check in reversed order if char is used	
	for(i = 90; i > 65; --i){

		if(decrypt[i - 65] == 0){
			encrypt[keylen + cnt] = i;	
			decrypt[i - 65] = keylen + cnt + 65;
			++cnt;
		}

	}
			
}
	

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]){


}

