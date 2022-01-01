#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int main(int argc , char * argv[]){
    struct mystat *ct = malloc (sizeof(struct mystat));
    ct->sz = argc - 1;
    int i;
    for(i = 1;i<argc;i++){
        //printf(1,"%d->" , atoi(argv[i]));
        ct->nums[i-1] = atoi(argv[i]);
    }
    printf(1 , "%d\n" , add(ct));
    exit();
}