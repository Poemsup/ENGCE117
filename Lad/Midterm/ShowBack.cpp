// Poemsup Buaman 65543206075-5 Sec 1 https://youtu.be/0ptBxkspojA
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  int data;
  struct Node *next;
} nd;

void ShowAll(nd **node);
nd *AddNode(nd **node, int num);
void ShowBack(nd **node);

int main() {
  nd *start = NULL;
  AddNode(&start, 10);
  AddNode(&start, 20);
  AddNode(&start, 30);
  AddNode(&start, 40);
  ShowAll(&start);
  ShowBack(&start);
  return 0;
} // End main()

void ShowAll(nd **node) {
  nd *current = *node;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  } // end while
  printf("\n");
} // end function

void ShowBack(nd **node) {
  nd *temp, *showback;
  nd *current = *node;
  while (current != NULL) {
    temp = current->next;
    current->next = showback;
    showback = current;
    current = temp;
  }
  *node = showback;
  ShowAll(node);
}

nd *AddNode(nd **node, int num) {
  nd *current;
  nd *newnode = new nd;
  newnode->next = NULL;
  newnode->data = num;
  if (*node == NULL) {
    *node = newnode;
  } else {
    current = *node;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newnode;
  }
  return newnode;
}
