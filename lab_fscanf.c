#include <stdio.h>
/*
 1 Recieves 2 filenames from command line arguments
 2. open first file, and read each line of the file
    a. assume at most 100 lines
    b. each line is a string w/o spaces, only letters, and at most 99 characters
    c. store all lines into an array
    d. if the files doesnt exist, print "<filename> doesnt exist: no such file or directory" 
    to stderr, and return 1
3. once all the lines have been read and stored in an array, write to the 2nd file, where:
    a. each line is formatted as  <line_number><space><string>
    b. line number starts from 1;
4. write makefile to compile program

*/

int main(int argc, char* argv[]){

    char arr[100][100];
    char msg[100];

    FILE* fp = fopen (argv[1], "r");
    if (fp == NULL){
        sprintf(msg, "%s doesn't exist", argv[1]);
        perror(msg);
        return 1; //exit 1 
    }

    int index = 0;
    while (fscanf(fp, "%d", arr[index]) != EOF){
        index ++;

    }
    //index == num of lines

    fclose(fp);

    fp = fopen(argv[2], "w");
    for (size_t i = 0; i < index; i++){
        fprintf(fp,"%d %s\n", i + 1, arr[i] );

    }
    fclose(fp);

}
