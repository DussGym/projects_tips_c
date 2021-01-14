/*

Dussin Francesco 4AI
Creare un nodo, che oltre al puntatore all'elemento successivo,
contenga delle informazioni rispetto ad un'automobile: nome
modello, targa, anno immatricolazione, cilindrata.

Dovrà essere possibile:

1) riempire una lista di automobili;
2) stampare le automobili presenti nella lista;
3) contare quante automobili ci sono nella lista;
4) invertire l'ordine delle automobile.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define massive 100

typedef struct car {

    char model[massive];
    char licenceplate[massive];
    char carregistrationyear[massive];
    char engine[massive];
}car;

typedef struct car node_car;

typedef struct node {

    struct node *next;
    struct car *vehicle;
}node;

typedef node *List; //List == node* same thing

void List_Add(List *head);
void List_Print(List head);
void List_Reverse(List *head);
int  List_Count(List head);
void List_InsertHead(List *head);
void List_InsertTail(List *head);
void List_PrintReverse(List *head);
void List_Bidirectional(List *head);

int main() {

    List head = NULL;

    int caffeine;

    List_Add(&head);
    List_Print(head);

    caffeine = List_Count(head);
    printf("\ncount: %d", caffeine);

    List_Add(&head);
    List_Print(head);

    caffeine = List_Count(head);
    printf("\ncount: %ààd", caffeine);

    List_Add(&head);
    List_Print(head);

    caffeine = List_Count(head);
    printf("\ncount: %d", caffeine);

    List_Add(&head);
    List_Print(head);

    caffeine = List_Count(head);
    printf("\ncount: %d\n", caffeine);

    List_Reverse(&head);
    List_Print(head);

    return 0;
}

void List_Add(List *head) { // ** propaghi le modifiche fatte all'
// interno della funzione List_Add nel main
// con ** la dereferenziazione accedi all'area di memoria
// alla quale il puntatore sta puntando

  int casual1;
  int casual2;

  List temp = *head; // quando metti un * come in questo caso dereferenzi un
  // puntatore percio head diventa il nuovo puntatore

  while (temp != NULL && temp -> next != NULL) {
      //printf("%p", temp);
      temp = temp -> next; // cosi temp 1-> [ ] 2-> [ ] punterà al 2
  }

  //printf("%p", temp);
  //add extra cells inside the memory (1)
  List newtemp = calloc(1, sizeof(node));
  newtemp -> vehicle = calloc(1, sizeof(node_car));

  printf("\n inject a new model:");
  scanf("%s", newtemp-> vehicle -> model); //HEAD 1
  printf("%s", newtemp-> vehicle -> model);

  printf("\n inject a new licenceplate:");
  scanf("%s", newtemp -> vehicle -> licenceplate); //2
  printf("%s", newtemp -> vehicle -> licenceplate);

  printf("\n inject a new carregistrationyear:");
  scanf("%s", newtemp -> vehicle -> carregistrationyear); //3
  //scanf("%s", &casual1);
  printf("%s", newtemp -> vehicle -> carregistrationyear);

  printf("\n inject a new engine:");
  scanf("%s", newtemp -> vehicle -> engine); //4
  //scanf("%s", &casual2);
  printf("%s\n\n", newtemp -> vehicle -> engine);

  //temp -> next = newtemp;
  //used for adding temp to the last position

  if(*head == NULL) { // se la lista è vuota fai questo

    *head = newtemp;
  } else {

    temp -> next = newtemp;
  }
}

void List_Print(List head) { //struct node_car

    List temp = head;

    while (temp != NULL) {

        printf("%s\n", temp -> vehicle -> model);
        printf("%s\n", temp -> vehicle -> licenceplate);
        printf("%s\n", temp -> vehicle -> carregistrationyear);
        printf("%s\n", temp -> vehicle -> engine);

        temp = temp -> next; //  temp 1-> [ ] 2-> [ ] 'll point to 2
    }
}

void List_Reverse(List *head) {

  List current = *head; //c
  List next = current -> next; //n
  List prev = NULL; //p

  if(current != NULL) {

    while(current != NULL) {

      current -> next = prev;
      prev = current;
      current = next;

      if(next != NULL) {

      next = next -> next;
      }
    }

    *head = prev;
  }
}

int List_Count(List head) {

  int rogers = 0;
  List temp = head;

  while(temp != NULL) {

    rogers++;
    temp = temp -> next;
  }

  return rogers;
}

void List_InsertHead(List head) {


}

void List_InsertTail(List head) {


}

void List_Bidirectional(List head) {


}

void List_PrintReverse(List head) {


}


//https://codeforwin.org/2015/09/c-program-to-insert-node-at-end-of-singly-linked-list.html
//https://www.programiz.com/c-programming/c-structures-pointers

/*

#include <stdio.h>
#include <stdlib.h>


/*Structure of a node
struct node {
    int data;          // Data
    struct node *next; // Address
}*head;


void createList(int n);
void insertNodeAtEnd(int data);
void displayList();


int main()
{
    int n, data;

    /*
     * Create a singly linked list of n nodes

    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Insert data at the end of the singly linked list

    printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertNodeAtEnd(data);

    printf("\nData in the list \n");
    displayList();

    return 0;
}

/*

 * Create a list of n nodes

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node

    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Reads data of node from the user

        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/*
 * Create a new node and inserts at the end of the linked list.

void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = NULL;

        temp = head;

        // Traverse to the last node
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}


/*
 * Display entire list

void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}
*/
