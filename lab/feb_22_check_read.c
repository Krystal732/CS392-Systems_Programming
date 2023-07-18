/*

22 Feb 2022
Write a program to check the user’s permission to read. 
The filename is passed as a command-line argument.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pwd.h> 



int main(int argc, char* argv[]) {

struct stat fp;
stat(argv[1], &fp); //0: file exists retrueve stat sucessfully, -1:error
if(fp.st.mode&(S_IRUSR) == 0){
    printf("NO PERMISSION TO READ");
}else printf("has permission");
//16 bit, last 9 bits rep the permissions 

//does group have permission to execute
if(fileinfo.st_mode&(S_IXGRP) == 0){
    printf("NO PERMISSION");
}

}