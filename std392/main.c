#include "std392io.h"
#include <stdbool.h>

 int main(int argc, char const *argv[]) {

   //  int array[5] = {1,2,-9,12,-3};
   //  char* string = "Hello!";

   //  /* Print integers to stdout */
   //  for (size_t i = 0; i < 5; i++) {
   //  output("", 'd', &array[i]);
   //  }
   //  output("", 's', string);

   //  int num;
   //  input("", 'd', &num);

   //  output("", 'd', &num);

    char newstr[1024] = {0};
    
    input("", 's', newstr);
    printf("%s\n", newstr);
    
   //  output("", 's', str);

    


    return 0;
    
 }
