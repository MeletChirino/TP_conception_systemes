#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include "lecteurcarte.h"

entrees *io;
int shmid;
int depart_timer;

void timer_initialiser()
{
 io=acces_memoire(&shmid);

 if(io==NULL)
 {
   printf("Erreur pas de memoire sh \n");
 }

 depart_timer=io->timer_sec;
}

int main()
{

    lecteurcarte_initialiser();

    while (1)
    {
        lecteurcarte_lire_carte();
	timer_initialiser();
    }

}
