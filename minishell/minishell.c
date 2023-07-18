/*
Krystal Hong
I pledge my honor that I have abided by the Stevens Honor System.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAXLINE 1024
#define MAXARGS 128
#define BLUE "\x1b[34;1m"
#define DEFAULT "\x1b[0m"
int main(){
    char cmdline[MAXLINE]; //command line
    while(1){
        char* temp = getcwd(NULL, 0);
        printf("%s[%s]%s> ", BLUE, temp, DEFAULT);
        free(temp);
        fgets(cmdline, MAXLINE, stdin);

        char cd_input[20];
        strncpy (cd_input, cmdline, 3);

        /* exit */
        if (strcmp(cmdline, "exit\n") == 0){
            return EXIT_SUCCESS;
        }

        /* cd */
        //cd with no arguments or ~ -> change directory to user's home directory

        else if ((strcmp(cmdline, "cd\n") == 0) || (strcmp(cmdline, "cd ~\n") == 0)){
            printf("yo take me to home directory pls\n");
        }
 
        else if (strcmp(cd_input, "cd ") == 0){
            printf(" go to this directory\n");
        }

    } 

}
