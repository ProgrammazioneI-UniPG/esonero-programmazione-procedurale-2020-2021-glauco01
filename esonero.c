#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char Stringa_iniziale [128], Chiave [128], Stringa_criptata [128], decriptata[128]; // Introduco i vari array nei quali andranno a finire i valori delle stringhe
int main(){
  int i;
  char scelta;
  time_t t;
  srand((unsigned) time(&t)); //Inizializzo la generazione di caratteri random
  printf("Digitare una stringa da cifrare di massimo 128 caratteri\n se ne verranno inseriti di più non verranno calcolati:");
  fgets(Stringa_iniziale, 128, stdin); //Prendo la stringa digitata dall'utente e la inserisco nell'array

int controllo = 0; //do un valore iniziale alla variabile di controllo
do{

   printf("Digitare 1 se si possiede una chiave\nDigitare 2 per generare una chiave randomicamente:\n");
   scanf("%c", &scelta);

  switch (scelta) //Distinguo i 2 casi: 1 se l'utente ha una chiave da digitare e la inserisco nell'array, 2 se devo generarla automaticamente e la stampo
{
    case '1':
    printf("Digitare una chiave che abbia caratteri maggiori o uguali a quelli della Stringa iniziale:");
    fgets(Chiave, 128, stdin);
    controllo=1;
    break;
    case '2':
    printf("La chiave é:");
    for (i= 0; i <strlen(Stringa_iniziale)-1; i++)
    {
      Chiave[i]=(rand()%96)+32; //Escludo i primi 32 caratteri i quali possono creare problemi quando vengono stampati
      printf("%c", Chiave[i]);
    }
    controllo=1;
    break;
    default:
    break;
  }
  char c;
  while((c= getchar()) != '\n' && c != EOF);  //pulisco il buffer di memoria per evitare errori
}while(!controllo); //con un do-while faccio in modo che nel caso in cui vengano digitati valori diversi da 1 e 2 venga ripetuta la domanda



    printf("\nEcco la tua stringa criptata:" );
    for (i=0; i < strlen(Stringa_iniziale)-1; i++)
    {
      Stringa_criptata[i]=Stringa_iniziale[i]^Chiave[i]; //Uso l'operatore XOR per criptare e stampare la stringa
      printf("%c", Stringa_criptata[i]);
    }
    printf("\nEcco la tua stringa decriptata:"); //Uso l'operatore XOR per decriptare e stampare la stringa
    for (i = 0; i < strlen(Stringa_iniziale)-1; i++)
    {
      decriptata[i]=Stringa_criptata[i]^Chiave[i];
      printf("%c",decriptata[i]);
}
}
