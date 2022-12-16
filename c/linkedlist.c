#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
int length(struct Node *ptr) {
  int count = 0;

  while (ptr != NULL) {
    ptr = ptr->next;
    count += 1;
  }

  return count;
}
void linkedListTraversal(struct Node *ptr) {

  if (length(ptr) == 0) {
    printf("Linked List is Empty!!!\n");
    return;
  }

  while (ptr != NULL) {
    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;
  }
}

struct Node *insertAtbeginning(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

  ptr->data = data;
  ptr->next = head;

  return ptr;
}

struct Node *insertAtEnd(struct Node *head, int data) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

  struct Node *p = head;
  while (p->next != NULL) {
    p = p->next;
  }

  p->next = ptr;
  ptr->data = data;
  return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index) {
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

  struct Node *p = head;

  if (index == 0) {
    head = insertAtbeginning(head, data);
    return head;
  }

  if (index > length(head) || index < 0) {
    printf("Invalid Index\n");
    return head;
  }

  int count = 0;

  while (count != index - 1) {
    count += 1;
    p = p->next;
  }

  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

struct Node *deleteAtIndex(struct Node *head, int index) {

  if (length(head) == 0) {
    printf("Linked List is Empty!!\n");
    return head;
  }

  if (index == 0) {
    struct Node *ptr = head;
    head = head->next;
    return head;
  }

  int count = 0;
  struct Node *p = head;
  while (p != NULL) {
    if (count == index - 1) {
      p->next = p->next->next;
      break;
    }
    p = p->next;
    count += 1;
  }
  return head;
}

int main() {

  struct Node *head;
  linkedListTraversal(head);
  head = (struct Node *)malloc(sizeof(struct Node));
  printf("Length Of Linked List is: %d\n", length(head));

  head->data = 03;
  head->next = NULL;
  printf("Length Of Linked List is: %d\n", length(head));
  linkedListTraversal(head);

    head = insertAtbeginning(head, 27);
    head = insertAtEnd(head, 1999);

    head = insertAtIndex(head, 222, 0);
    head = insertAtIndex(head, 999, 2);

    printf("before deletion\n");
    linkedListTraversal(head);

    printf("Length Of Linked List is: %d\n", length(head));
    head = deleteAtIndex(head, 0);
    head = deleteAtIndex(head, 2);
    printf("After deletion\n");
    linkedListTraversal(head);
    printf("Length Of Linked List is: %d\n", length(head));
  return 0;
}