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
  for (curr = list->head; curr != NULL; curr = curr->next) {
    if (curr == list->head) {
      printf("HEAD:\n\tCurr: %p\n\tNext: %p\n", curr, curr->next);
    } else if (curr == list->tail) {
      printf("TAIL:\n\tPrev: %p\n\tCurr: %p\n", curr->prev, curr);
    } else {
      printf("ITEM:\n\tPrev: %p\n\tCurr: %p\n\tNext: %p\n", curr->prev, curr, curr->next);
    } 
  }
}

struct Item* GetItem(struct List* list, int index) {
  struct Item* curr = list->head;
  int counter = 0;
  for (curr; curr != NULL; curr = curr->next) {
    if (counter == index)
      break;
    counter++;
  }
  return curr;
}

int GetIndex(struct List *list, struct Item* item) {
  struct Item* curr = list->head;
  int counter = 0;
  for (curr; curr != NULL; curr = curr->next) {
    if (curr == item)
      break;
    counter++;
  }
  return counter;
}

void Insert(struct List *list, struct Item* item, int i) {

}

struct Item* Remove(struct List* list, int index) {
  struct Item* item = GetItem(list, index);
  if (item == NULL)
    return NULL;

  if (list->head == list->tail) {
    list->head = NULL;
    list->tail = NULL;
  } else if (item == list->head) {
    list->head = item->next;
    item->next->prev = NULL;
  } else if (item == list->tail) {
    list->tail = item->prev;
    item->prev->next = NULL;
  } else {
    struct Item* prev = item->prev;
    struct Item* next = item->next;
    prev->next = next;
    next->prev = prev;
  }

  return item;
}

void Delete(struct List* list, int index) {
  struct Item* item = Remove(list, index);
  if (item)
    free(item);
}

void Clear(struct List* list) {
  struct Item* curr = list->head;
  for (curr; list->head != NULL; curr = list->head) {
    Delete(list, 0);
  }
}