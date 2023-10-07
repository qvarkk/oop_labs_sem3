#include <stdio.h>
#include <stdlib.h>
#include "subj.h"

int DoMenu(char* s[], int len) {
  int i;
  for (i = 1; i <= len; i++) {
    printf("%i. %s\n", i, s[i]);
  }
  printf("> ");
  fflush(stdin);
  scanf("%i", &i);
  return i<0 || i>len ? 0 : i;
}

int main(void) {
  struct List list;
  struct Base* item;
  enum ItemType type;
  char *menuActions[] = {"(none)", "Add Item", "Count", "Print List", "Print Item", "Insert", "Delete", "Clear"};
  char *typeNames[] = {"(unknown)", "Star", "Planet"};
  
  int buff;
  do {
    buff = DoMenu(menuActions, 7);
    switch (buff) {
      case 1:
        type = DoMenu(typeNames, 2);
        if (type != None) {
          item = Create(type);
          InputItem(item);
          Add(&list, (struct Item*)item);
          printf("Item was added!\n\n");
        } else {
          printf("Wrong item type!\n\n");
        }
        break;
      case 2:
        printf("There\'s %i items in list\n\n", Count(&list));
        break;
      case 3:
        PrintSpaceItems(&list);
        break;
      case 4:
        printf("Enter index: ");
        scanf("%i", &buff);
        item = (struct Base*)GetItem(&list, buff);
        if (item)
          PrintItem(item);
        break;
      case 5:
        printf("Enter index: ");
        scanf("%i", &buff);
        type = DoMenu(typeNames, 2);
        if (type != None) {
          item = Create(type);
          InputItem(item);
          Insert(&list, (struct Item*)item, buff);
          printf("Item was inserted!\n\n");
        }
        break;
      case 6:
        printf("Enter index: ");
        scanf("%i", &buff);
        Delete(&list, buff);
        break;
      case 7:
        Clear(&list);
        printf("List was cleared\n\n");
        break;
      case -1:
        return 0;
        break;
      default:
        printf("Wrong option!\n\n");
        break;
    }
  } while (1);

}
