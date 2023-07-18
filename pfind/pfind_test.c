
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <libgen.h>


int main(int argc, char *argv[]){
    //lets first check if its valid permission string

    // char perm[10];
    // strcpy(perm, argv[1]);
    // void usage(){
    //     printf("Error: Permissions string '%s'is invalid.\n", perm);
    // }
    // if(strlen(perm) != 9){
    //     usage();
    //     return EXIT_FAILURE;
    // }else (printf("ok!\n"));
    // return 0;


    // struct stat fileinfo;
    // char filename[1024];
    // strcpy(filename, argv[1]);
    // char fileperm[9];

    // char path[1024];
    // if(realpath(filename, path)){
    //     printf("%s\n", path);
    // }
    // else{
    //     printf("Error: %s\n", strerror(errno));
    // }

//     struct stat fileinfo;
//     char dir[1024];
//     strcpy(dir, argv[1]);
//     char fileperm[9];
//     char dirpath[1024];
//     realpath(dir,dirpath);
//     struct dirent *dp;
//     DIR* FD;

        
//     if ((FD = opendir(dir)) == NULL ){
//         printf("Error: Cannot open directory '%s'. Permission denied.", dirpath);
//         return EXIT_FAILURE;
//     }
    
//     //0: file exists retrieve stat sucessfully, -1:error

//     int status = stat(dir, &fileinfo);
//     if(status != 0){
//         printf("Error: %s\n", strerror(errno));
//         return EXIT_FAILURE ;
//     }
// FILE *this_file;
// void itdir (char* path){
    
//     printf("%s\n",path);
//     DIR* d = opendir(path);
//     struct dirent* dp;
//     while ((dp = readdir(FD)) != NULL){
//         char filepath[1024];
//         if (!strcmp (dp->d_name, "."))
//             continue;
//         if (!strcmp (dp->d_name, ".."))    
//             continue;
        
//         if(dp -> d_type != DT_DIR){
//             printf("%s\n", dp->d_name);
//         }
//         if (dp -> d_type == DT_DIR){
//             // printf("%s/%s:\n",basename(path), dp-> d_name);
//             printf("%s:\n", dp-> d_name);

//             char d_path[1024];
//             sprintf(d_path, "%s/%s", path, dp->d_name);
//             itdir(d_path);
//         }

        

//     }
//     closedir(d);
// }
// itdir(dirpath);





// void list_dir(char *path, char *perm) {
//   DIR *dir;
//   struct dirent *entry;
//   dir = opendir(path);
  
//   if (dir == NULL) {
//     printf("Failed to open directory.\n");
//     return;
//   }
//   while ((entry = readdir(dir)) != NULL) {
//     if(entry->d_type == DT_DIR) {
//       if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
//         char *new_path = (char *)malloc(strlen(path) + strlen(entry->d_name) + 1);
//         sprintf(new_path, "%s/%s", path, entry->d_name);
//         list_dir(new_path, perm);
//         free(new_path);
//       }
//       } else {
//         struct stat fileinfo;
//         int status = stat(entry->d_name, &fileinfo);
//             if (S_ISREG(fileinfo.st_mode)) {
        
//             //create perm string 
//             char fileperm[9];
//             (fileinfo.st_mode & S_IRUSR) ? strcat(fileperm, "r") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IWUSR) ? strcat(fileperm, "w") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IXUSR) ? strcat(fileperm, "x") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IRGRP) ? strcat(fileperm, "r") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IWGRP) ? strcat(fileperm, "w") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IXGRP) ? strcat(fileperm, "x") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IROTH) ? strcat(fileperm, "r") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IWOTH) ? strcat(fileperm, "w") : strcat(fileperm, "-");
//             (fileinfo.st_mode & S_IXOTH) ? strcat(fileperm, "x") : strcat(fileperm, "-");
//             //compare if this fileperm == perm if yes then print path
//             if (strcmp(fileperm, perm) == 0){
//                 printf("%s/%stest\n", path, entry->d_name);

//             }
//         }


//         printf("%s/%s\n", path, entry->d_name);
//       }
//     }
//     closedir(dir);
// }
// list_dir(argv[1], "rwxrwxrwx");

    struct stat fileinfo;
    if(stat(argv[1], &fileinfo) < 0)    
        return 1;

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
    printf("%s\n", fileperm);


    return 0;

}