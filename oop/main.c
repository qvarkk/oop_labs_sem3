#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
  struct List list;
  struct Item* item = (struct Item*)calloc(1, sizeof(struct Item));
  Add(&list, item);
  item = (struct Item*)calloc(1, sizeof(struct Item));
  Add(&list, item);
  item = (struct Item*)calloc(1, sizeof(struct Item));
  Add(&list, item);
  item = (struct Item*)calloc(1, sizeof(struct Item));
  Add(&list, item);
  printf("%i\n", Count(&list));
  PrintList(&list);
}