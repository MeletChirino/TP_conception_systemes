#include <stdio.h>
#include <voyants.h>
#include <timer.h>
#include <baseclient.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include "lecteurcarte.h"

entrees *io;
int shmid;


int main()
{

    lecteurcarte_initialiser();
    voyants_initialiser();
    timer_initialiser();

    while (1)
    {
        lecteurcarte_lire_carte();
	
    }

}
