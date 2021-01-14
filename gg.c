#include<stdio.h>
#include<stdlib.h>

//struttura
 struct AnimaleZoo{

    //char razza[20];
    char nome[20];
    //int id;
    //int eta;
    //float dim;
    //float peso;
    struct AnimaleZoo *next;
    struct AnimaleZoo *prev;
}AnimaleZoo;
typedef struct AnimaleZoo *Animale;

void stampa(struct AnimaleZoo *head) {

    Animale tmp = head;

    if (head == NULL)
        printf("  La tua lista è vuota\n");

        while (tmp != NULL) {
          printf("\n\n  Nome Animale : %s\n", tmp -> nome);
        //printf("  Targa Auto : %s\n", tmp->targa);
        //printf("  Anno di immatricolazione : %d\n", tmp->anno);
        //printf("  Cilindrata : %d\n", tmp->cilindrata);
        printf("\n");
        tmp = tmp->next;
    }
}
/*
void InserisciInTesta(Animale *head){

}

void EliminaInPosizione(){

}
*/

int main (){

    Animale *head;

    Animale temp = *head;
    //Animale newtemp = NULL;
    Animale newNodo = NULL;
    //Animale p = NULL;
    //Animale *next=NULL;
    //p=head;


    printf("Quanti animali vuoi inserire? -->");
    int NumeroAnimali=0;
    scanf("%d",&NumeroAnimali);
    int i=0;
    for (i=0;i<NumeroAnimali;i++){
        newNodo = malloc(sizeof(Animale));

        printf("Nome Animale : %d ", i+1);
        scanf(" %s", newNodo ->nome);

          if(temp != NULL) {

            newNodo -> next = temp;
            temp -> prev = newNodo;
          }

          temp = newNodo;
          *head = temp;
    }

    stampa(*head);

return 0;
}
