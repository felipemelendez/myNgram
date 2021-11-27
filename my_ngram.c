#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_ASCII_CHARACTERS 128 // 128 ASCII characters (from 0 to 127)

int main(int argc, char** argv) {

FILE *fp;
fp = fopen("./text-file.txt", "w"); //create a txt file with the write mode
int i;

for(i = 0; i < argc; i++) {
  if(argv[i+1] != NULL){
    fprintf(fp,"%s",argv[i+1]); //prints to stream (in other words to the text file created) the content of argv
  }
}
fclose(fp);
fp = NULL; 

/* file pointer - open and read the created text file; in this case we are parsing the source code */
fp = fopen("./text-file.txt", "r");

//create an object with 128 spaces, one for each printable ASCII character (from 0 to 127)
int count[NUMBER_OF_ASCII_CHARACTERS] = { 0 }; 

/* initialize a character holding variable and get the first character in the FILE (stored as int because EOF is assigned a -1 in C) */
int c = fgetc(fp);

/* for as long as we can get characters... */
while(c != EOF) {  
  /* count each particular character */
  if(c != 34) { // we don't want to count the quotation marks (ASCI value of " is 34)
    count[c] += 1; // this will only add 1 if a new instance of c is found
    //printf("This is c: %c\nThis is count[c]: %d\n", c, count[c]);
  } 
  //printf("This is c: %c\nThis is count[c]: %d\n", c, count[c]);
  c = fgetc(fp); // get the next character
}

/* print the results, but only if the count is different from zero */
for(i = 0; i < NUMBER_OF_ASCII_CHARACTERS; i++) {
  if(count[i] > 0) {
  printf("%c:%d\n", i, count[i]);
  }
}
/* close the file */
fclose(fp);
return EXIT_SUCCESS;
}
