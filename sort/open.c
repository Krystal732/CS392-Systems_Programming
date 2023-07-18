 #include <stdio.h>
 #include <getopt.h>
 #include <stddef.h>
 #include <stdlib.h>

int main () {
int line_num = 0;
char* arr = (char *)malloc(1024 * sizeof(char *));
// int arr[50];

   FILE *fp = fopen ("test.txt", "r");
   
    if (fp == NULL){
      printf("Error: Cannot open. No such file or directory.\n");
      return EXIT_FAILURE;
    }
    while (fscanf(fp, "%s", &arr[line_num]) != EOF){
      line_num++;
    }
    fclose(fp);

    for(int i = 0; i < line_num; i++){
		  printf("%s\n", arr[i]);
	  }
    free(arr);
   
   return(0);
}