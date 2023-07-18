#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){

    DIR* dp = opendir(argv[1]);
    struct dirent* dirp;
    struct stat fi;

    while((dirp = readdir(dp)) != NULL){
        puts( dirp->d_name );
        stat( argv[1] + / + dirp->d_name ,&fi);
    }





    char arr* = getcwd( NULL, 0 );
    

return 0;
}


