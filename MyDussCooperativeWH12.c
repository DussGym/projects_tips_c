/*

Dussin Francesco 4Ai 1/11/2021

Ricerca cooperativa generalizzato
Il processo padre genera un vettore, di dimensione MAXELEM,
di valori double casuali compresi tra ValMin e ValMax.
Il processo padre domanda l'elemento, che può essere ripetuto, da cercare.
Poi, il processo padre, domanda quanti figli generare
(o decide in base ad una banale IA) per
effettuare una ricerca di elemento ripetuto su vettore.
Dopo fork opportuni ciascun figlio cerca, su elementi non ordinati,
nella sua porzione di vettore un elemento che potrebbe presentarsi piu' volte.
Nota: il figlio, trovata la corrispondenza,
la stampa a video insieme alla relativa posizione.
L'ultimo figlio cerca fino in fondo, perche' non sempre la dimensione
MAXELEM é divisibile senza resto con il numero di figli.
Creare poi una funzione per generare array
con elementi casuali senza ripetizioni.
Ritestare l'algoritmo di ricerca su array molto grandi,
confrontandolo anche con l'algoritmo di ricerca sequenziale con unico processo.
Consegnare un foglio elettronico con i dati rilevati
e una veloce analisi degli stessi.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <time.h>
#include <sys/wait.h>
#include <signal.h>

// range elements
#define MAX 10
// maximum amount of elements given to the array
#define EL 10

void Array_Print(double array1[]);
void Array_Casually_Refilled(double array1[]);

int main() {

  double research;
 	double array1[EL];

 	int fd[2];
 	pid_t P;

 	  Array_Casually_Refilled(array1);
    stampa_array(array1);
    printf("\n");

    printf("\n number to be research ");
    scanf("%lf", &research);

    int son;
    printf("\n Number of childs? \n");
    scanf(" %d ", &son);

    int count1 = 0;
    int z;
    z = D / f;

    while(f > 0) {

        pipe(fd);
        Pfork = fork();

        if (Pfork == 0) {

            double sub_array[z];
            int i,k;

            for(i = z * count1; i < z + z * count1 && k < z; i++) { // ?

                sub_array[k] = array1[i];
                k++;
            }

            int count2 = 0;
            int op;

            for(op = 0; op < EL; op++) {

              if (array1[op] == research) {

                count2++;
              }
            }

            close(fd[0]);
            write(fd[1], &count2, sizeof(count2));
          }

          else if (Pfork > 0) {

            int readingpipe;

            close(fd[1]);
            read(fd[0], &readingpipe, sizeof(readingpipe));

            if (f == 1) {

              int res;

              res = res + readingpipe;
              printf("result--> %d ", res);
            }
          }

          f--;
          count1++;
        }

    return 0;
}

void Array_Casually_Refilled(double array1[]) {

    int i = 0;
    for(i = 0; i < EL; i++) {

      array1[i] = 1 + rand() % EL;
    }
}

void Array_Print(double array1[]) {

    printf("\n Array_Print \n");

    int i = 0;

    for(i = 0; i < EL; i++) {

      printf("%lf element:", array1[i]);

    }
}
