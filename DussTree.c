/*
Dussin Francesco 4Ai 1/11/2020

Implementare in linguaggio C una lista (bidirezionale) di animali dello zoo,
utilizzare la struct del file zoo.c:

il programma deve prevedere le seguenti operazioni

- Inserire un  nuovo animale in testa o in coda

- stampare gli elementi della lista

- cancellare un animale

--------------------------------------------------------------------------------

scrivere un programma in C per gestire una lista double linked

in particolare deve essere possibile:
inserire in testa
inserire in coda
stampa lista nell'ordine di inserimento dei dati
stampa al contrario
cercare e cancellare elemento qualsiasi
*/

/*
in a doubly linked lists each node has multiple references...
one pointing to the next node and one to the previous
 _  _  _
|_||_||_| 1-2-3
1:prev reference
2:data inside the node
3:next reference
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////

typedef struct farm {

  int data;
  struct farm *left;
  struct farm *right;
}farm;

typedef struct farm *List;

void List_Print(List root); // x
void List_RecursivePrint(List root); // x
List List_GetNewNode(); // x
void List_RootAdd(List *root); // x

////////////////////////////////////////////////////////////////////////////////

int main() { //no return --> void

  List head = NULL;

  List_RootAdd(&head);
  //List_Print(head);

  return 0;
}

////////////////////////////////////////////////////////////////////////////////

void List_Print(List root) {
/*
  List temp = root;

  if(temp != NULL) {

    List_Print(root -> left);
  }
  */
}

////////////////////////////////////////////////////////////////////////////////

void List_RecursivePrint(List root) {
/*
  List temp = root;

  if(temp != NULL) {

    List_RecursivePrint(root -> left);
  }
*/
}

////////////////////////////////////////////////////////////////////////////////

List List_GetNewNode() {

  List newtemp = calloc(1,sizeof(farm));
  printf("insert new data\n");
  printf("gggggggggggggggggggggggggggggggggggg");
  scanf("%d", &newtemp -> data);

  return newtemp;
}

////////////////////////////////////////////////////////////////////////////////

void List_RootAdd(List *root) {

  List temp = *root;
  List pov = NULL;

  int cycle, lr;
  int i = 0;
/*

add 1 Left
add 2 Left
add 3 Right
add 4 right etc

*/
  printf("METHOD: List_RootAdd --> Number of new roots\n");
  scanf("%d", &cycle);

  printf("METHOD: List_RootAdd --> Left 0 || Right 1 LINK\n");
  scanf("%d", &lr);

  for (i = 0; i < cycle; i++) {

      pov = List_GetNewNode();
      printf("\nbbbbbbbbbbbbbbbbbbbb\n");

      if(lr == 0) {
printf("\naaaaaaaaaaaaaaaaaaaaaaa\n");
        pov -> left = temp;
        pov -> right = NULL;
        printf("\ncccccccccccccccccccccccccc\n");
      } else if(lr == 1) {

printf("\nddddddddddddddddddddd\n");
        pov -> left = NULL;
        pov -> right = temp;
        printf("\neeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
      }
printf("\nfffffffffffffffffffffffffffffff\n");
      temp = pov;
      printf("\nggggggggggggggggggggggggggg\n");
    }
printf("\nhhhhhhhhhhhhhhhhhhhhhhh\n");
  *root = temp;
  printf("\niiiiiiiiiiiiiiiiiiiiiiii\n");
}
