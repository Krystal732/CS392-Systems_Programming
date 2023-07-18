/* 

Krystal Hong
I pledge my honor that I have abided by the Stevens Honor Sytsem.

*/
 #include <stdio.h>
 #include <getopt.h>
 #include <stddef.h>
 #include <stdlib.h>
 #include "mergesort.h" 


void usage(){
    printf("Usage: ./sort [-i|-d] filename\n"
    "-i: Specifies the file contains ints.\n"
    "-d: Specifies the file contains doubles.\n"
    "filename: The file to sort.\n");
}

 int main(int argc, char *argv[]){

   if(argc == 1){
     usage();
     return EXIT_FAILURE;
   }
  int i_flag=0, d_flag=0;   
  int opt;
  while ((opt = getopt(argc, argv, ":id")) != -1) 
  {
     switch (opt) 
     {
      case 'i':
        i_flag++;
        break;
      case 'd':
        d_flag++;
        break;
      case ':':
        printf("Error: No input file specified.\n");
        usage();
        return EXIT_FAILURE;
      case '?':
        printf("Error: Uknown option '%c' recieved\n", optopt);
        usage();
        return EXIT_FAILURE;
     }
  }

  if (i_flag + d_flag > 1){
      printf("Error: Too many flags specified\n");
      return EXIT_FAILURE;
  } else if (argc > 3){
      printf("Error: Too many files specified\n");
      return EXIT_FAILURE;
  }else if (i_flag == 1){
    
  }
int max_lines = 1024;
int line_num = 0;
char** arr = (char **)malloc(max_lines * sizeof(char *));

//if there is a file after flag
  if(optind < argc){

    FILE *fp = fopen(argv[optind], "r");
    if (fp == NULL){
      printf("Error: Cannot open '%s'. No such file or directory.\n", argv[optind]);
      return EXIT_FAILURE;
    }
    //scans lines untill end of file is reached
    while (fscanf(fp, "%s", arr[line_num]) != EOF){
      line_num++;
    }

//im sorry for the seg faults ;-;


  }
//no files
  else{
    printf("Error: No input file specified. \n");
    return EXIT_FAILURE;
  }

  //flag actions
  //copy into array of int or dbl, call merge then print then free
  if (i_flag == 1){
    int* int_arr = (int *)malloc(max_lines * sizeof(int));
    for(int i = 0; i < line_num; i++){
			int_arr[i] = atoi(arr[i]);
		}
    mergesort(int_arr, line_num, sizeof(int), int_cmp);

    for(int i = 0; i < line_num; i++){
		  printf("%i\n", int_arr[i]);
	  }
    free(int_arr);
  }
  else if(d_flag == 1){
    double* dbl_arr = (double *)malloc(max_lines * sizeof(double));
    for(int i = 0; i < line_num; i++){
			dbl_arr[i] = atof(arr[i]);
		}
    mergesort(dbl_arr, line_num, sizeof(double), dbl_cmp);

    for(int i = 0; i < line_num; i++){
		  printf("%f\n", dbl_arr[i]);
	  }
    free(dbl_arr);

  }


  for (int i = 0; i < line_num; i++) {
		free(arr[i]);
	}
	free(arr);

  return EXIT_SUCCESS;
}