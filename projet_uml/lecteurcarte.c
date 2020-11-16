#include <unistd.h>
#include <stdio.h>
#include <lcarte.h>
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

 if(carte_inseree()/*&&voyants disponible*/)
 {  
   baseclient_authentifier(numero);

   if(baseclient_authentifier(numero)==1)
   {

     if(io->timer_sec%2==0&& io->timer_sec==8)
     {
       io->led_charge=VERT;
     }
     else if(io->bouton_charge==1)
     {
       io->led_dispo=OFF;
       io->timer_sec=8;
       io->bouton_charge=0;
     }
     else
     {
       io->led_charge=OFF;
       io->timer_sec=0;
     }
     if(io->led_dispo==OFF/*&&carte_retiree()*/)
     {
       //charger batterie
     }
     else if(io->timer_sec%2==0&&io->timer_sec==8)
     {
       io->led_defaut=ROUGE;
     }
     else
     {
       io->led_defaut=ROUGE;
       io->timer_sec=0;
     }
   }
   
 }

 attente_retrait_carte();
 liberation_ports();
}

