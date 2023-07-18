 #include <stdio.h>
 #include <getopt.h>
 #include <stddef.h>
 #include <stdlib.h>

int main (int argc, char *argv[]) {
int index = 0;

double* arr = (double *)malloc(1024 * sizeof(double *));

FILE *fp = fopen (argv[1], "r");
    
  if (fp == NULL){
    printf("Error: Cannot open. No such file or directory.\n");
    return EXIT_FAILURE;
  }

  while (fscanf(fp, "%lf", &arr[index]) != EOF){
    index++;
  }
  fclose(fp);
  void print_bytes(void *p, size_t len){
    size_t i;
    for (i = 0; i < len; ++i)
        printf("%02X", ((unsigned char*)p)[i]);
    printf("\n");
  }
  void print_double(double x){
    print_bytes(&x, sizeof(x));
  }
  for(int i = 0; i < index; i++){
    // arr[i] = arr[i] *2;
    // printf("%lf\n", arr[i]);
    print_double(arr[i]);
  }

  return(0);
}