#include <stdlib.h>
#include <stdio.h>
#include <string.h>





int main(){



 if(chown( argv[1], userid, -1) != 0){
 pererror("ERROR!") 



/*
Stack
    grows downwards
    managed by compiler during compilation time
    static allocation

Heap
    grows upwards
    managed by programmers/users
    during run-time
    dynamic allocation
*/
int a = 10;
printf("%p", &a);

char arr[10];
print("%p", arr);

int* ptr = &a;
int** pptr = &ptr;
char* ptr2 = arr;

print("%d", *ptr);




int a = 10;
int b = a;
int* c = &a;

b++; //a=10, b=11, c= 0x1000
c++; //a=10, b=11, c=0X1004     bc int is 4 bytes
(*c)++; //a=10, b=11, c=0x1004  bc we changed c so no longer point to a
//if c address did not change then a=11

void*

int length;
scanf("%d", &length);
int* arr = (int*)malloc(sizeof(int) * length);

arr = (int*);


free(arr);


}

