#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "subj.h"

const char* const menuActions[11] = { "(none)", "Add Item", "Count", "Print List", "Print Item", "Search By Name", "Search By Distance", "Sort List", "Insert", "Delete", "Clear" };
const char* const typeNames[3] = { "(unknown)", "Star", "Planet" };

int DoMenu(const char* const* s, int len) {
    int i;
    for (i = 1; i <= len; i++) {
        std::cout << i << ". " << s[i] << std::endl;
    }
    std::cout << "> ";
    fflush(stdin);
    std::cin >> i;
    return i<0 || i>len ? 0 : i;
}

int main(void) {
    struct List list;
    struct Base* item;
    enum ItemType type;

    int buffInt;
    int start, end = -1;
    char* buffStr = (char*)calloc(1, sizeof(char) * 100);
    do {
        buffInt = DoMenu(menuActions, 9);
        switch (buffInt) {
        case 1:
            type = (enum ItemType)DoMenu(typeNames, 2);
            if (type != None) {
                item = Create(type);
                InputItem(item);
                Add(&list, (struct Item*)item);
                std::cout << "Item was added!\n" << std::endl;
            }
            else {
                std::cout << "Wrong item type!\n" << std::endl;
            }
            break;
        case 2:
            std::cout << "There\'s " << Count(&list) << " items in list\n" << std::endl;
            break;
        case 3:
            PrintSpaceItems(&list);
            break;
        case 4:
            std::cout << "Enter index: ";
            std::cin >> buffInt;
            item = (struct Base*)GetItem(&list, buffInt);
            if (item)
                PrintItem(item);
            break;
        case 5:
            std::cout << "Enter name: ";
            std::cin >> buffStr;
            SearchByName(&list, buffStr);
            break;
        case 6:
            std::cout << "Enter the interval: ";
            std::cin >> start >> end;
            SearchByDistance(&list, start, end);
            break;
        case 7:
            SortList(&list);
            break;
        case 8:
            std::cout << "Enter index: ";
            std::cin >> buffInt;
            type = (enum ItemType)DoMenu(typeNames, 2);
            if (type != None) {
                item = Create(type);
                InputItem(item);
                Insert(&list, (struct Item*)item, buffInt);
                std::cout << "Item was inserted!\n" << std::endl;
            }
            break;
        case 9:
            std::cout << "Enter index: ";
            std::cin >> buffStr;
            Delete(&list, buffInt);
            break;
        case 10:
            Clear(&list);
            std::cout << "List was cleared\n" << std::endl;
            break;
        case -1:
            return 0;
            break;
        default:
            std::cout << "Wrong option!\n" << std::endl;
            break;
        }
    } while (1);
}
