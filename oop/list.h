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
struct Item* GetItem(struct List*, int);
int GetIndex(struct List*, struct Item*);
void Insert(struct List*, struct Item*, int);
struct Item* Remove(struct List*, int);
void Delete(struct List*, int);
void Clear(struct List*);

#endif 