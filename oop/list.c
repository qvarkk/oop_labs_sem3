#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void Add(struct List* list, struct Item* item) {
  if (list->head == NULL) {
    list->head = item;
    list->tail = item;
  } else {
    list->tail->next = item;
    item->prev = list->tail;
    list->tail = item;
  }
}

int Count(struct List* list) {
  int i;
  struct Item* curr = list->head;
  for (i = 0; curr != NULL; i++) {
    curr = curr->next;
  }
  return i;
}

void PrintList(struct List* list) {
  struct Item* curr;
  for (curr = list->head; curr->next != NULL; curr = curr->next) {
    if (curr->prev == NULL) {
      printf("HEAD:\n\tCurr: %p\n\tNext: %p\n", curr, curr->next);
    } else {
      printf("ITEM:\n\tPrev: %p\n\tCurr: %p\n\tNext: %p\n", curr->prev, curr, curr->next);
    }
  }
  printf("TAIL:\n\tPrev: %p\n\tCurr: %p\n", curr->prev, curr);
}