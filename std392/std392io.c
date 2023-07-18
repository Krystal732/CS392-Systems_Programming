
/*
Krystal Hong
I pledge my honor that I have abided by the Stevens Honor System
*/
#include "std392io.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdbool.h>

//helper int to str
char* __itoa(int num, char* str){
    void swap(char *x, char *y) {
        char t = *x; *x = *y; *y = t;
    }
    void reverse(char str[], int length){
        int start = 0;
        int end = length -1;
        while (start < end)
        {
            swap((str+start), (str+end));
        
            start++;
            end--;
        }
    }

    int i = 0;
    bool isNegative = false;

    if (num == 0){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0){
        isNegative = true;
        num = -num;
    }
     while (num != 0){
        str[i++] = num % 10 + '0';
        num = num/10;
    }
    if (isNegative){
        str[i++] = '-';
    }
    str[i] = '\0';
    reverse(str, i);
 
    return str;

}
/*
if filename empty -> print data to terminal
if file exists, append data to end of the file otherwise create new file 
*/

int output(char* filename, char format, void* data){

    if (data == NULL){
        errno = EIO;
        return -1;
    }
    //opening the file
    if(filename[0] != '\0'){
        int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND);
        if (fd < 0){
            errno = EIO;
            return -1;
        }
        //output string
        if (format == 's'){
            char* str = (char*)data;
            write(fd, str, sizeof(str));
            write(1, "\n", 1);

            return 0;

        }
        //output integer
        if (format == 'd'){
            int num = *((int*)data);
            char str[100];

            write(fd, __itoa(num, str), sizeof(__itoa(num, str)));
            write(1, "\n", 1);

            return 0;
            
        }
        else{
            errno = EIO;
            return -1;

        }
    }
    //if filename is "" output to terminal

    //output string
    if (format == 's'){
        char* str = (char*)data;
        write(1, str, sizeof(str));
        write(1, "\n", 1);
        return 0;
    }
    //output integer
    if (format == 'd'){
        int num = *((int*)data);
        char str[100];
        write(1, __itoa(num, str), sizeof(__itoa(num, str)));
        write(1, "\n", 1);

        return 0;

    }
    else{
        errno = EIO;
        return -1;
    }
}



/*
if filename empty -> recieve data from keyboard
file DNE -> errno ENOENT
exists -> read one line
*/
int input(char* filename, char format, void* data){
    //read from stdin
    if (filename[0] == '\0'){
        if( format == 's'){
            char arr[1024];
            // int index = 0;
            // int curr_size = 128;
            if (read(0, &arr, sizeof(arr)) < 0){
                errno = EIO;
                return -1;
            }
            // allocate 128 bytes to buffer and if full 128 more
            // while(read(1, &tmp, 1) != 0) {
            //     if (index == curr_size) {
            //         char* newarr = malloc(curr_size + 128);
            //         for (size_t j = 0; j < curr_size; j++) {
            //             newarr[j] = arr[j];
            //         }
            //         free(arr);
            //         arr = newarr;
            //         curr_size += 128;
            //     }
            //     arr[index] = tmp;
            //     index++;
            // }
            
            // arr[index] = '\0';  
            

            memcpy(data, &arr, sizeof(arr));
            
            // free(arr);
            return 0;
            

        }
        if (format == 'd'){
            char num[128];
            if (read(0, &num, sizeof(num)) < 0){
                errno = EIO;
                return -1;
            }
            int number = atoi(num);
            memcpy(data, &number, sizeof(int));
         
            return 0;
        }
        else{
            errno = EIO;
            return -1;
        }

    }
    //read from file
    else{
        int fd = open(filename, O_RDONLY);
        if (fd < 0){
            errno = ENOENT;
            return -1;
        }
        if ( format == 's'){
            char* arr = malloc(128);
            char tmp;
            int index = 0;
            int curr_size = 128;
            //first get inode of desired file
            int inode;
            if (read(fd, &tmp, 1) < 0){
                errno = EIO;
                return -1;
            }
            //check if opened
            int opened;
            struct stat file_stat;  
            int ret;  
            ret = fstat (fd, &file_stat);  
            if (ret < 0) {  
                errno = EIO;
                return -1;
            } 
            inode = file_stat.st_ino;

            //iterate through proc/pid/fd 
            int pid_n = getpid();
            char* pid;
            pid = __itoa(pid_n, pid);
            char* dpath = "/proc/";
            strcat(dpath, pid);
            strcat(dpath, "/fd/");
            
            DIR *dir;
            struct dirent *entry;
            dir = opendir(dpath);
            //compare inodes
            while ((entry = readdir(dir)) != NULL) {
                if (open(entry->d_name, O_RDONLY) < 0){
                    errno = EIO;
                    return 1;
                }
                int fd1 = open(entry->d_name, O_RDONLY);
                struct stat file_stat1;  
                int ret1;  
                int inode1;
                ret1 = fstat (fd1, &file_stat1);  
                if (ret1 < 0) {  
                    errno = EIO;
                    return -1;
                } 
                if (inode == inode1){
                    opened = 1;
                    exit;
                }
                close(fd1);
            }



            //if opened check if reached end of file
            if (lseek(fd,0,SEEK_CUR) == lseek(fd,0,SEEK_END)){
                errno = EIO;
                return -1;
            }
            while(read(fd, &tmp, 1) != 0) {
                if (index == curr_size) {
                    char* newarr = malloc(curr_size + 128);
                    memset(newarr, 0, curr_size);
                    for (size_t j = 0; j < curr_size; j++) {
                        newarr[j] = arr[j];
                    }
                    free(arr);
                    arr = newarr;
                    curr_size += 128;
                }
                arr[index] = tmp;
                index++;
            }
            arr[index] = '\0';            
            memcpy(data, arr, sizeof(arr));
            free(arr);
            return 0;  
                
        }
        //output integer
        if (format == 'd'){

            char num[128];
            if (read(fd, &num, sizeof(num)) < 0){
                errno = EIO;
                return -1;
            }
            int number = atoi(num);
            memcpy(data, &number, sizeof(int));
            return 0;
            

        }
        else{
            errno = EIO;
            return -1;
        }

    }

    
}

//close the files
int clean(){
    int pid_n = getpid();
    char* pid = malloc(sizeof(pid));
    __itoa(pid_n, pid);

    
    //open dir and iterate through and close each
    DIR *dir;
    struct dirent *entry;
    dir = opendir("/proc/self/fd");
    int fd;
    //dirent to fd
    while ((entry = readdir(dir)) != NULL) {
        if (fd = open(entry->d_name, O_RDONLY) < 0){
            errno = EIO;
            return 1;
        }
        close(fd);
    }
    free(pid);
    closedir(dir);
    return 0;
}
