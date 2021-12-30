#include "types.h"
#include "user.h"
#include "fcntl.h"


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


//give command : incr 7
//it will output 8
int main(int argc , char * argv[]){
    printf(1 , "%d\n" , incr(my_atoi(argv[1])));
    exit();
}