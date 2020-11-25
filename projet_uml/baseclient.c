#include <baseclient.h>
#include <unistd.h>
#include <stdio.h>

int clients[2]={1,2};

int baseclient_authentifier(int numero)
{
 int i;

 for(i=0;i<2;i++)
 {
   if(numero == clients[i])
	return 1;
 }
 return 0;
}