#ifndef LIST_H
#define LIST_H

#include "item.h"

struct List {
  struct Item* head;
  struct Item* tail;
};

void Add(struct List*, struct Item*);
int Count(struct List*);
void PrintList(struct List*);

#endif 