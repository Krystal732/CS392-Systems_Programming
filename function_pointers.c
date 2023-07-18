#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int add(int a, double b)


struct UPSInfo{
    char* ID;
    int anotherID;
    char* addr;
};

struct FedexInfo{
    double weight;
    char* addr;

}

void* ups(void* args){
    struct UPSInfo* temp = (struct UPSInfo*) args;
    printf("%d\n", temp->anotherID);
    printf("%s\n", (*temp).ID);


}

void* fedex(void* args)

check(){
    //call function
    void* (*)(void*), void*
    //check mem leak
}

//void* can be casted to any parameter
void ship(void* (*dispatch)(void*),void* package){
    int* pc = (int*) dispatch(package);
    printf("%d\n", *pc);
    free(pc);
}


int main (){

    int (*ptr)(int, double) = &add;
    int c = ptr(3,4);

    printf("%p", &add);


    struct UPSInfo pack;
    pack.ID = "hello";

    ship(&ups, (void*)&pack);



    int*c = (int*)malloc(sizeof(int));
    *c = 3;
    return (void*)c;



    return 0;
}