#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <libgen.h>
#include <fcntl.h>
#include <errno.h>


int main (int argc, char *argv[]) {
int line_num = 1;
char c;
char** arr = (char **)malloc(1024 * sizeof(char *));

   FILE *fp = fopen (argv[1], "r");
   

  if (fp == NULL){
    printf("Error: Cannot open. No such file or directory.\n");
    return EXIT_FAILURE;
  }
  while((c=fgetc(fp)) != EOF){
    if(c=='\n'){
      line_num++;
    }
  }
  rewind(fp);
  for (int i = 0; i < line_num; i++){
    arr[i] = (char*) malloc(sizeof(char) * 64);
  }


  char buffer[66];

  int index = 0;
    while(fgets(buffer, sizeof(buffer), fp)){
      
      arr[index] = strdup(buffer);      
      index++;
    }

  
  fclose(fp);

  for(int i = 0; i < line_num; i++){
    printf("%s", arr[i]);
  }
  printf("\n");


  for (int i = 0; i < line_num; i++) {
		free(arr[i]);
	}
	free(arr);
  
  return 0;
}