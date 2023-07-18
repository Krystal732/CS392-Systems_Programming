/*
Write a C program to read double numbers from a file and store them into an array.
 For each element in the array, print out their addresses one byte at a time.
In the output, each line represents the number as well as its address.
 For each address, print each byte of the address in the format such as  “0x2F” 
 with a space between every two bytes.
    The number of lines in a file is unknown;
    File name is passed as a command-line argument;
    When printing each byte, use the format “0x%x” to print in hex.
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char const *argv[]){
    long int a = 20;
    char* p = (char*)&a;

    for ( i=0, i<sizeof(long int); i++){
        printf("%x ", p[i]);
    }
}