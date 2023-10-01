#include <stdio.h>
#include <stdlib.h>
#include "subj.h"

int DoMenu(char* s[], int len) {
  int i;
  for (i = 1; i <= len; i++) {
    printf("%i. %s\n", i, s[i]);
  }
  printf("0. Exit\n");
  printf("> ");
  fflush(stdin);
  scanf("%i", &i);
  return i<0 || i>len ? -1 : i;
}

int main(void) {
  struct List list;
  struct Item* item;
  char *menu[] = {"(none)", "Add Item", "Count", "Print List", "Insert", "Delete", "Clear", "Exit"};
  
  int buff;
  do {
    buff = DoMenu(menu, 6);
    switch (buff) {
      case 1:
        do {
          printf("Star - 1\nPlanet - 2\n> ");
          fflush(stdin);
          scanf("%d", &buff);
          if (buff == 1 || buff == 2) 
            break;
          else
            printf("Wrong input\n");
        } while (1);
        struct Base* base = Create(buff);
        InputItem(base);
        Add(&list, (struct Item*)base);
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
  } while (1);

}
