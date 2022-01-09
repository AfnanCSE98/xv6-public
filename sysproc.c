#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include <stddef.h>
#include "fcntl.h"
#include "stat.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}


int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//added by afnan
int
sys_getsize(void)
{
  return myproc()->sz;
}

void sys_shutdown(void){
  outw(0xB004, 0x0|0x2000);
  outw(0x604, 0x0|0x2000);
}

//give command : incr 7
//it will output 8
int sys_incr(void){
  int num;
  argint(0,&num); //retrieving first integer argument

  //cprintf("%d - Inside system call!",argc);

  return num + 1;
}

int sys_add(void){
  struct mystat *ct;
  argptr (0 , (void*)&ct ,sizeof(*ct));
  int s = 0;
  int i;
  for(i=0;i<ct->sz;i++){
    s+=ct->nums[i];
    //cprintf("%d " , ct->nums[i]);
  }
  return s; 
}
//command : substr alupotol 3 5
//output  : potol
char* sys_substr(void){
  static char *str;
  int start_idx , len;
  
  argint(1 , &start_idx);
  argint(2 , &len);
  argstr(0 , &str);
  char* s = &str[0];
  int i;
  int k = 0;
  for(i = start_idx ; i < start_idx+len ; i++){
    s[k++] = str[i];
  }
  s[k]='\0';
  return s;
}

//command : sort 3 5 2 4
//output : 2 3 4 5
int* sys_sort(void){
  struct mystat *ct;
  argptr (0 , (void*)&ct ,sizeof(*ct));
  int n = ct->sz;
 
  int temp, j, k;
   
  for (j = 0; j < n; ++j)
  {
    for (k = j + 1; k < n; ++k)
    {
        if (ct->nums[j] > ct->nums[k])
        {
          temp = ct->nums[j];
          ct->nums[j] = ct->nums[k];
          ct->nums[k] = temp;
        }
    }
  }
  return ct->nums;
}