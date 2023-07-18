/*

inode: uniqure across the system files on the hard drive
file descriptor: unique only within a process files opened by a process non-neg integers

stdin (0), stdout, stderr


*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char const *argv[]){
    //creates a file and opens it
    int fd = creat( argv[1], S_IRWXU );
    printf("fd: %d\n", fd);

    

    return 0;


}
