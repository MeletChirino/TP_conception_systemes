#include <baseclient.h>
#include <unistd.h>
#include <stdio.h>

entrees *io;
int shmid;

int b_charge()
{
  io=acces_memoire(&shmid);
  
  if(io->b_charge==1)
  {
    return 1;
  }
  else
  {
    return 0 
  }
}

int b_stop()
{
  io=acces_memoire(&shmid);
  
  if(io->b_stop==1)
  {
    return 1;
  }
  else
  {
    return 0 
  }
}

