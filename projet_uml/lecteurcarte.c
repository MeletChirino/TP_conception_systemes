#include <unistd.h>
#include <stdio.h>
#include <lcarte.h>
#include <voyants.h>
#include <baseclient.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include "lecteurcarte.h"

int numero;
entrees *io;
int shmid;

void lecteurcarte_initialiser()
{
 initialisations_ports();
 io=acces_memoire(&shmid);
}

void lecteurcarte_lire_carte()
{
 if(io->led_dispo==VERT)
 {
  attente_insertion_carte();
  numero = lecture_numero_carte();
  printf("numero lu : %d \n", numero);
 }

 if(carte_inseree())
 {  
   printf("auth %d \n",baseclient_authentifier(numero));
 
   if(baseclient_authentifier(numero)) 
   {
      printf("coucou2");
      voyants_set_charge();
   }
   else
   {
      printf("coucou \n");
      voyants_set_defaut();
   }
 }
 attente_retrait_carte();
 liberation_ports();
}

