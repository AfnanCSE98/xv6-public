#include "types.h"
#include "user.h"
#include "fcntl.h"
#include "stat.h"

//added by afnan
//converts string to int
int my_atoi(char *str)
{
    int i;
    int sign;
    int val;
    int nbr;

    i = 0;
    sign = 1;
    val = 0;
    nbr = 0;
    if (str[0] == '-')
    {
        sign = -1;
        str++;
    }
    i = 0;
    while(str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
        nbr = (int) (str[i] - '0');
        val = (val * 10) + nbr;
        i++;
    }
    i++;
    return (val * sign);
}

int main(int argc , char * argv[]){
    struct mystat *ct = malloc (sizeof(struct mystat));
    ct->sz = argc - 1;
    int i;
    for(i = 1;i<argc;i++){
        //printf(1,"%d->" , my_atoi(argv[i]));
        ct->nums[i-1] = my_atoi(argv[i]);
    }
    printf(1 , "%d\n" , add(ct));
    exit();
}