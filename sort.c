#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

int main(int argc , char * argv[]){
    struct mystat *ct = malloc (sizeof(struct mystat));
    ct->sz = argc - 1;
    int i;
    for(i = 1;i<argc;i++){
        ct->nums[i-1] = atoi(argv[i]);
    }

    int *sorted_nums = sort(ct);

    for(int i=0;i<ct->sz;i++){
        printf(1 , "%d " , *(sorted_nums+i));
    }
    printf(1 , "\n");
    exit();
}