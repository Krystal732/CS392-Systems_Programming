#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid = fork();
    // 
    if (pid < 0){
        perror("fork");
        return -1;
    }
    else if (pid == 0){
        printf("I am the child \n");
        return 0;
    }
    printf("I am the parent of %d\n", pid);
    return 0;
////////////////////////////////////////////////

    if ((pid = fork())<0) return -1;
    else if (pid==0) sleep(2);
    else{
        w = -100;
    }
    printf("I am %d, child of %d",getpid(), getppid());
}
