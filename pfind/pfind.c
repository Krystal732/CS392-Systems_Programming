/* 

Krystal Hong
I pledge my honor that I have abided by the Stevens Honor System.

*/

#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>



int main(int argc, char *argv[]){
    //lets first check if its valid permission string

    char perm[10];
    strcpy(perm, argv[2]);
    void usage(){
        printf("Error: Permissions string '%s'is invalid.\n", perm);
    }
    if(strlen(perm) != 9){
        usage();
        return EXIT_FAILURE;
    }else if (perm[0] != 'r' && perm[0] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[1] != 'w' && perm[1] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[2] != 'x' && perm[2] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[3] != 'r' && perm[3] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[4] != 'w' && perm[4] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[5] != 'x' && perm[5] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[6] != 'r' && perm[6] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[7] != 'w' && perm[7] != '-' ){
        usage();
        return EXIT_FAILURE;
    }else if (perm[8] != 'x' && perm[8] != '-' ){
        usage();
        return EXIT_FAILURE;
    }

    //now take argv[1] directory and check if any match given valid perms

 void list_dir(char *path, char *perm) {
  DIR *dir;
  struct dirent *entry;
  dir = opendir(path);
  
  if (dir == NULL) {
    printf("Failed to open directory.\n");
    return;
  }
  while ((entry = readdir(dir)) != NULL) {
    if(entry->d_type == DT_DIR) {
      if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
        char *new_path = (char *)malloc(strlen(path) + strlen(entry->d_name) + 1);
        sprintf(new_path, "%s/%s", path, entry->d_name);
        list_dir(new_path, perm);
        free(new_path);
      }
      } else {
        struct stat fileinfo;
        if(stat(argv[1], &fileinfo) < 0){
            printf("Error: %s\n", strerror(errno));

        }  
            
            //create perm string 
            char fileperm[9];
            (fileinfo.st_mode & S_IRUSR) ? strcat(fileperm, "r") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IWUSR) ? strcat(fileperm, "w") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IXUSR) ? strcat(fileperm, "x") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IRGRP) ? strcat(fileperm, "r") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IWGRP) ? strcat(fileperm, "w") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IXGRP) ? strcat(fileperm, "x") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IROTH) ? strcat(fileperm, "r") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IWOTH) ? strcat(fileperm, "w") : strcat(fileperm, "-");
            (fileinfo.st_mode & S_IXOTH) ? strcat(fileperm, "x") : strcat(fileperm, "-");

            //compare if this fileperm == perm if yes then print path
            if (strcmp(fileperm, perm) == 0){
                printf("%s/%s\n", path, entry->d_name);
            }
            memset(fileperm, 0, sizeof(fileperm));
      }
    }
    closedir(dir);
}

char dir[1024];
char dirpath[1024];
DIR* odir;
strcpy(dir, argv[1]);
realpath(dir, dirpath);

if ((odir = opendir(dir)) == NULL ){
    printf("Error: Cannot open directory '%s'. Permission denied.", dirpath);
    return EXIT_FAILURE;
}
list_dir(dirpath, perm);
return 0;
}