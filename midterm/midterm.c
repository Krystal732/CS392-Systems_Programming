/*
Krystal Hong
I pledge my honor that I have abided by the Stevens Honor System
*/

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
int index = 0;

int* arr = (int *)malloc(1024 * sizeof(int *));
int* new = (int *)malloc(1024 * sizeof(int *));


//open file
FILE *fp = fopen (argv[1], "r");
    
  if (fp == NULL){
    printf("Error: Cannot open. No such file or directory.\n");
    return EXIT_FAILURE;
  }
//write into array
  while (fscanf(fp, "%d", &arr[index]) != EOF){
    index++;
  }
//   int* new = arr;
  fclose(fp);

//incomplete :(
  void reverse_array( void* old_array, void* new_array, int len ){
    // for (int i=0; i<len; i++){
          
    // }
    // memcpy(new_array, old_array, len*sizeof(int));
  }
//reverse int arr
  void reverse_array_INT( int* old_array, int* new_array, int len ){
    int count = len;
    for (int i=0; i<len; i++){
        new_array[i] = old_array[count-1];
        count--;
    }
  }
  
  reverse_array_INT(arr, new, index);
//   reverse_array(arr,new,index);

  FILE *w = fopen (argv[2], "w");
  for(int n=0;n<index;n++) {

        fprintf(fp,"%d\n",new[n-1]);

     }
 fclose(w);



  free(arr);
  free(new);
  return(0);
}