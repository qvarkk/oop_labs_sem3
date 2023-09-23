#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
  struct List list;
  struct Item* item;
  
  int buff;
  while (1) {
    printf("1. Add item\n2. Count\n3. Print List\n4. Insert\n5. Delete\n6. Clear\n0. Exit\n\nInsert option: ");
    scanf("%i", &buff);
    fflush(stdin);

    switch (buff) {
      case 1:
        item = (struct Item*)calloc(1, sizeof(struct Item));
        Add(&list, item);
        printf("Item was added!\n\n");
        break;
      case 2:
        printf("There\'s %i items in list\n\n", Count(&list));
        break;
      case 3:
        PrintList(&list);
        break;
      case 4:
        printf("Enter index: ");
        scanf("%i", &buff);
        item = (struct Item*)calloc(1, sizeof(struct Item));
        Insert(&list, item, buff);
        printf("Item was inserted!\n\n");
        break;
      case 5:
        printf("Enter index: ");
        scanf("%i", &buff);
        Delete(&list, buff);
        break;
      case 6:
        Clear(&list);
        printf("List was cleared\n\n");
        break;
      case 0:
        return 0;
        break;
      default:
        printf("Wrong option!\n\n");
        break;
    }
  }

}